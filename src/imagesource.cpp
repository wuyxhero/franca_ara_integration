// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#include "imagesource.h"

#include <QDebug>
#include <QElapsedTimer>
#include <QImageReader>
#include <QQmlContext>
#include <QQuickView>
#include <QQmlEngine>

#include "SomeIpNetworkThreadTypes.h"
#include <iostream>
#include <math.h>

#define IMAGE_FEED_PATH                                                        \
    "/home/user/devel/GENIVI/franca_ara_integration/src/feed"
#define MAX_IMAGE_ID 228

// Internal helpers

// Just a safety check to avoid ridiculous behavior if buggy input
static int limit_id(int id) {
   // TODO: report if index is outside limits
   // Use DLT.  Possibly QDebug wrapper on DLT
   return std::min(0, std::max(MAX_IMAGE_ID, id));
}

static QString image_url(int frameId)
{
    qDebug() << QString("%1/l_image%2.png").arg(IMAGE_FEED_PATH).arg(frameId);
    auto s = QString("%1/l_image%2.png").arg(IMAGE_FEED_PATH).arg(frameId);
    std::cout << "Using image path: " << s.toStdString() << std::endl;
    return QString("%1/l_image%2.png").arg(IMAGE_FEED_PATH).arg(frameId);
}

static QRect get_bounding_qrect(BoxDefinition box) {
   return QRect(box.x, box.y, box.width, box.height);
}

typedef std::pair<QLine, QLine> Drawn_Lane_Boundary_t;

static Drawn_Lane_Boundary_t get_bounding_lines(const LaneLineDefinition &l, const LaneLineDefinition &r) {
   return Drawn_Lane_Boundary_t(
         QLine(l.upper_x, l.upper_y, l.lower_x, l.lower_y),
         QLine(r.upper_x, r.upper_y, r.lower_x, r.lower_y)
         );
}


// Public functions called by networking class/thread:

// Init, called from main at startup
void ImageSource::connectImageProvider(QQuickView &view)
{
    std::cout << "LOG(connecting)" << std::endl;

    view.engine()->addImageProvider("imageprovider", &_provider);
    view.engine()->rootContext()->setContextProperty("imageprovider",
                                                     &_provider);

    QObject::connect(this, SIGNAL(imageReady(const QImage &)), &_provider,
                     SLOT(setImage(const QImage &)));

    // Put ourselves (image source) as the source of some meta data to QML
    view.engine()->rootContext()->setContextProperty("metadatasource",
                                                     this);

}

void ImageSource::newFrameId(int frameID) {
    printf("newFrameId: %d\n", frameID);
    QImageReader reader(image_url(limit_id(frameID)));
    printf("emit imageReady\n");
    emit imageReady(reader.read()); // Signal to ImageProvider
}

void ImageSource::newVehicleIdentification (const BoxDefinition &box) {
   QRect rect = get_bounding_qrect(box);
   printf("emit vehicleIdentified\n");
   emit vehicleIdentified(rect); // Signal to QML
}

void ImageSource::newLaneIdentification (const LaneLineDefinition &left, const LaneLineDefinition &right) {
   Q_UNUSED(left);
   Q_UNUSED(right);

   Drawn_Lane_Boundary_t lines = get_bounding_lines(left, right);
   printf("emit laneIdentified\n");
   emit laneIdentified(lines.first, lines.second);  // Signal to QML
}

QLine ImageSource::getLeftLaneLine () {

    static    auto x1 = new QLine(10,20,30,40);
    return *x1;
}

QLine ImageSource::getRightLaneLine () {

    static            auto x2 = new QLine(10,20,30,40);
    return *x2;
}




