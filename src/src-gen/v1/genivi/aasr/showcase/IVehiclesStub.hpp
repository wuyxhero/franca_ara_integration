/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v201805221014.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_GENIVI_AASR_SHOWCASE_I_Vehicles_STUB_HPP_
#define V1_GENIVI_AASR_SHOWCASE_I_Vehicles_STUB_HPP_

#include <functional>
#include <sstream>




#include <v1/genivi/aasr/showcase/IVehicles.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/Deployment.hpp>
#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <CommonAPI/Struct.hpp>
#include <cstdint>
#include <vector>

#include <mutex>

#include <CommonAPI/Stub.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace genivi {
namespace aasr {
namespace showcase {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service IVehicles. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class IVehiclesStubAdapter
    : public virtual CommonAPI::StubAdapter,
      public virtual IVehicles {
 public:
    ///Notifies all remote listeners about a change of value of the attribute Vehicles.
    virtual void fireVehiclesAttributeChanged(const ::v1::genivi::aasr::showcase::IVehicles::ListOfVehicles& Vehicles) = 0;



    virtual void deactivateManagedInstances() = 0;

    void lockVehiclesAttribute(bool _lockAccess) {
        if (_lockAccess) {
            vehiclesMutex_.lock();
        } else {
            vehiclesMutex_.unlock();
        }
    }

protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */

    std::recursive_mutex vehiclesMutex_;
};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for IVehicles.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class IVehiclesStubRemoteEvent
{
public:
    virtual ~IVehiclesStubRemoteEvent() { }

    /// Verification callback for remote set requests on the attribute Vehicles
    virtual bool onRemoteSetVehiclesAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, ::v1::genivi::aasr::showcase::IVehicles::ListOfVehicles _value) = 0;
    /// Action callback for remote set requests on the attribute Vehicles
    virtual void onRemoteVehiclesAttributeChanged() = 0;
};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service IVehicles to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class IVehiclesStub
    : public virtual CommonAPI::Stub<IVehiclesStubAdapter, IVehiclesStubRemoteEvent>
{
public:
    typedef std::function<void (bool _rv)>SetFloatingPointPrecisionReply_t;

    virtual ~IVehiclesStub() {}
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> clientId) = 0;
    void lockInterfaceVersionAttribute(bool _lockAccess) { static_cast<void>(_lockAccess); }

    /// Provides getter access to the attribute Vehicles
    virtual const ::v1::genivi::aasr::showcase::IVehicles::ListOfVehicles &getVehiclesAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireVehiclesAttributeChanged(::v1::genivi::aasr::showcase::IVehicles::ListOfVehicles _value) {
    auto stubAdapter = CommonAPI::Stub<IVehiclesStubAdapter, IVehiclesStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireVehiclesAttributeChanged(_value);
    }
    void lockVehiclesAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<IVehiclesStubAdapter, IVehiclesStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockVehiclesAttribute(_lockAccess);
    }

    /// This is the method that will be called on remote calls on the method SetFloatingPointPrecision.
    virtual void SetFloatingPointPrecision(const std::shared_ptr<CommonAPI::ClientId> _client, IVehicles::FloatingPointPrecision _precision, SetFloatingPointPrecisionReply_t _reply) = 0;

    
    using CommonAPI::Stub<IVehiclesStubAdapter, IVehiclesStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<IVehiclesStubAdapter, IVehiclesStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<IVehiclesStubAdapter, IVehiclesStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef IVehiclesStubRemoteEvent RemoteEventType;
    typedef IVehicles StubInterface;
};

} // namespace showcase
} // namespace aasr
} // namespace genivi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_GENIVI_AASR_SHOWCASE_I_Vehicles_STUB_HPP_
