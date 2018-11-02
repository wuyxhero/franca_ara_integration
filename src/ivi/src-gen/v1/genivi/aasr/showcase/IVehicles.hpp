/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v201805221014.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_GENIVI_AASR_SHOWCASE_I_VEHICLES_HPP_
#define V1_GENIVI_AASR_SHOWCASE_I_VEHICLES_HPP_




#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/Deployment.hpp>
#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <CommonAPI/Struct.hpp>
#include <CommonAPI/Types.hpp>
#include <CommonAPI/Variant.hpp>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace genivi {
namespace aasr {
namespace showcase {

class IVehicles {
public:
    virtual ~IVehicles() { }

    static inline const char* getInterface();
    static inline CommonAPI::Version getInterfaceVersion();
    
    struct FloatingPointPrecision : CommonAPI::Enumeration< int32_t> {
        enum Literal : int32_t {
            Bit32 = 0,
            Bit64 = 1
        };
    
        FloatingPointPrecision()
            : CommonAPI::Enumeration< int32_t>(static_cast< int32_t>(Literal::Bit32)) {}
        FloatingPointPrecision(Literal _literal)
            : CommonAPI::Enumeration< int32_t>(static_cast< int32_t>(_literal)) {}
    
        inline bool validate() const {
            switch (value_) {
                case static_cast< int32_t>(Literal::Bit32):
                case static_cast< int32_t>(Literal::Bit64):
                return true;
            default:
                return false;
            }
        }
    
        inline bool operator==(const FloatingPointPrecision &_other) const { return (value_ == _other.value_); }
        inline bool operator!=(const FloatingPointPrecision &_other) const { return (value_ != _other.value_); }
        inline bool operator<=(const FloatingPointPrecision &_other) const { return (value_ <= _other.value_); }
        inline bool operator>=(const FloatingPointPrecision &_other) const { return (value_ >= _other.value_); }
        inline bool operator<(const FloatingPointPrecision &_other) const { return (value_ < _other.value_); }
        inline bool operator>(const FloatingPointPrecision &_other) const { return (value_ > _other.value_); }
    
        inline bool operator==(const Literal &_value) const { return (value_ == static_cast< int32_t>(_value)); }
        inline bool operator!=(const Literal &_value) const { return (value_ != static_cast< int32_t>(_value)); }
        inline bool operator<=(const Literal &_value) const { return (value_ <= static_cast< int32_t>(_value)); }
        inline bool operator>=(const Literal &_value) const { return (value_ >= static_cast< int32_t>(_value)); }
        inline bool operator<(const Literal &_value) const { return (value_ < static_cast< int32_t>(_value)); }
        inline bool operator>(const Literal &_value) const { return (value_ > static_cast< int32_t>(_value)); }
    };
    typedef CommonAPI::Variant< float, double>  FlexibleFloatingPoint;
    struct FlexibleFloatingPointContainer : CommonAPI::Struct< FloatingPointPrecision, FlexibleFloatingPoint> {
    
        FlexibleFloatingPointContainer()
        {
            std::get< 0>(values_) = FloatingPointPrecision();
            std::get< 1>(values_) = FlexibleFloatingPoint();
        }
        FlexibleFloatingPointContainer(const FloatingPointPrecision &_precision, const FlexibleFloatingPoint &_floatingPoint)
        {
            std::get< 0>(values_) = _precision;
            std::get< 1>(values_) = _floatingPoint;
        }
        inline const FloatingPointPrecision &getPrecision() const { return std::get< 0>(values_); }
        inline void setPrecision(const FloatingPointPrecision &_value) { std::get< 0>(values_) = _value; }
        inline const FlexibleFloatingPoint &getFloatingPoint() const { return std::get< 1>(values_); }
        inline void setFloatingPoint(const FlexibleFloatingPoint &_value) { std::get< 1>(values_) = _value; }
        inline bool operator==(const FlexibleFloatingPointContainer& _other) const {
        return (getPrecision() == _other.getPrecision() && getFloatingPoint() == _other.getFloatingPoint());
        }
        inline bool operator!=(const FlexibleFloatingPointContainer &_other) const {
            return !((*this) == _other);
        }
    
    };
    struct BoundingBox : CommonAPI::Struct< uint32_t, uint32_t, uint32_t, uint32_t> {
    
        BoundingBox()
        {
            std::get< 0>(values_) = 0ul;
            std::get< 1>(values_) = 0ul;
            std::get< 2>(values_) = 0ul;
            std::get< 3>(values_) = 0ul;
        }
        BoundingBox(const uint32_t &_topLeftX, const uint32_t &_topLeftY, const uint32_t &_width, const uint32_t &_height)
        {
            std::get< 0>(values_) = _topLeftX;
            std::get< 1>(values_) = _topLeftY;
            std::get< 2>(values_) = _width;
            std::get< 3>(values_) = _height;
        }
        inline const uint32_t &getTopLeftX() const { return std::get< 0>(values_); }
        inline void setTopLeftX(const uint32_t &_value) { std::get< 0>(values_) = _value; }
        inline const uint32_t &getTopLeftY() const { return std::get< 1>(values_); }
        inline void setTopLeftY(const uint32_t &_value) { std::get< 1>(values_) = _value; }
        inline const uint32_t &getWidth() const { return std::get< 2>(values_); }
        inline void setWidth(const uint32_t &_value) { std::get< 2>(values_) = _value; }
        inline const uint32_t &getHeight() const { return std::get< 3>(values_); }
        inline void setHeight(const uint32_t &_value) { std::get< 3>(values_) = _value; }
        inline bool operator==(const BoundingBox& _other) const {
        return (getTopLeftX() == _other.getTopLeftX() && getTopLeftY() == _other.getTopLeftY() && getWidth() == _other.getWidth() && getHeight() == _other.getHeight());
        }
        inline bool operator!=(const BoundingBox &_other) const {
            return !((*this) == _other);
        }
    
    };
    typedef std::unordered_map< uint8_t, ::v1::genivi::aasr::showcase::IVehicles::BoundingBox> BoundingBoxes;
    struct Vehicle : CommonAPI::Struct< uint8_t, FlexibleFloatingPointContainer, FlexibleFloatingPointContainer> {
    
        Vehicle()
        {
            std::get< 0>(values_) = 0u;
            std::get< 1>(values_) = FlexibleFloatingPointContainer();
            std::get< 2>(values_) = FlexibleFloatingPointContainer();
        }
        Vehicle(const uint8_t &_id, const FlexibleFloatingPointContainer &_currentDistance, const FlexibleFloatingPointContainer &_collisionTime)
        {
            std::get< 0>(values_) = _id;
            std::get< 1>(values_) = _currentDistance;
            std::get< 2>(values_) = _collisionTime;
        }
        inline const uint8_t &getId() const { return std::get< 0>(values_); }
        inline void setId(const uint8_t &_value) { std::get< 0>(values_) = _value; }
        inline const FlexibleFloatingPointContainer &getCurrentDistance() const { return std::get< 1>(values_); }
        inline void setCurrentDistance(const FlexibleFloatingPointContainer &_value) { std::get< 1>(values_) = _value; }
        inline const FlexibleFloatingPointContainer &getCollisionTime() const { return std::get< 2>(values_); }
        inline void setCollisionTime(const FlexibleFloatingPointContainer &_value) { std::get< 2>(values_) = _value; }
        inline bool operator==(const Vehicle& _other) const {
        return (getId() == _other.getId() && getCurrentDistance() == _other.getCurrentDistance() && getCollisionTime() == _other.getCollisionTime());
        }
        inline bool operator!=(const Vehicle &_other) const {
            return !((*this) == _other);
        }
    
    };
    struct ListOfVehicles : CommonAPI::Struct< uint16_t, std::string, std::vector< Vehicle >, BoundingBoxes> {
    
        ListOfVehicles()
        {
            std::get< 0>(values_) = 0u;
            std::get< 1>(values_) = "";
            std::get< 2>(values_) = std::vector< Vehicle >();
            std::get< 3>(values_) = BoundingBoxes();
        }
        ListOfVehicles(const uint16_t &_frameId, const std::string &_frameHash, const std::vector< Vehicle > &_detectedVehicles, const BoundingBoxes &_boxes)
        {
            std::get< 0>(values_) = _frameId;
            std::get< 1>(values_) = _frameHash;
            std::get< 2>(values_) = _detectedVehicles;
            std::get< 3>(values_) = _boxes;
        }
        inline const uint16_t &getFrameId() const { return std::get< 0>(values_); }
        inline void setFrameId(const uint16_t &_value) { std::get< 0>(values_) = _value; }
        inline const std::string &getFrameHash() const { return std::get< 1>(values_); }
        inline void setFrameHash(const std::string &_value) { std::get< 1>(values_) = _value; }
        inline const std::vector< Vehicle > &getDetectedVehicles() const { return std::get< 2>(values_); }
        inline void setDetectedVehicles(const std::vector< Vehicle > &_value) { std::get< 2>(values_) = _value; }
        inline const BoundingBoxes &getBoxes() const { return std::get< 3>(values_); }
        inline void setBoxes(const BoundingBoxes &_value) { std::get< 3>(values_) = _value; }
        inline bool operator==(const ListOfVehicles& _other) const {
        return (getFrameId() == _other.getFrameId() && getFrameHash() == _other.getFrameHash() && getDetectedVehicles() == _other.getDetectedVehicles() && getBoxes() == _other.getBoxes());
        }
        inline bool operator!=(const ListOfVehicles &_other) const {
            return !((*this) == _other);
        }
    
    };
};

const char* IVehicles::getInterface() {
    return ("genivi.aasr.showcase.IVehicles:v1_0");
}

CommonAPI::Version IVehicles::getInterfaceVersion() {
    return CommonAPI::Version(1, 0);
}


} // namespace showcase
} // namespace aasr
} // namespace genivi
} // namespace v1

namespace CommonAPI {
}


// Compatibility
namespace v1_0 = v1;

#endif // V1_GENIVI_AASR_SHOWCASE_I_VEHICLES_HPP_