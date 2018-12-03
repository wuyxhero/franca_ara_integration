/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v201805221014.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_GENIVI_AASR_SHOWCASE_I_DRIVING_LANE_HPP_
#define V1_GENIVI_AASR_SHOWCASE_I_DRIVING_LANE_HPP_




#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/Deployment.hpp>
#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <CommonAPI/Struct.hpp>
#include <CommonAPI/Types.hpp>
#include <cstdint>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace genivi {
namespace aasr {
namespace showcase {

class IDrivingLane {
public:
    virtual ~IDrivingLane() { }

    static inline const char* getInterface();
    static inline CommonAPI::Version getInterfaceVersion();
    struct LaneType : CommonAPI::Struct< uint16_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t> {
    
        LaneType()
        {
            std::get< 0>(values_) = 0u;
            std::get< 1>(values_) = 0ul;
            std::get< 2>(values_) = 0ul;
            std::get< 3>(values_) = 0ul;
            std::get< 4>(values_) = 0ul;
            std::get< 5>(values_) = 0ul;
            std::get< 6>(values_) = 0ul;
        }
        LaneType(const uint16_t &_frameId, const uint32_t &_lowerLeftPointX, const uint32_t &_lowerLeftPointY, const uint32_t &_lowerRightPointX, const uint32_t &_lowerRightPointY, const uint32_t &_intersectionPointX, const uint32_t &_intersectionPointY)
        {
            std::get< 0>(values_) = _frameId;
            std::get< 1>(values_) = _lowerLeftPointX;
            std::get< 2>(values_) = _lowerLeftPointY;
            std::get< 3>(values_) = _lowerRightPointX;
            std::get< 4>(values_) = _lowerRightPointY;
            std::get< 5>(values_) = _intersectionPointX;
            std::get< 6>(values_) = _intersectionPointY;
        }
        inline const uint16_t &getFrameId() const { return std::get< 0>(values_); }
        inline void setFrameId(const uint16_t &_value) { std::get< 0>(values_) = _value; }
        inline const uint32_t &getLowerLeftPointX() const { return std::get< 1>(values_); }
        inline void setLowerLeftPointX(const uint32_t &_value) { std::get< 1>(values_) = _value; }
        inline const uint32_t &getLowerLeftPointY() const { return std::get< 2>(values_); }
        inline void setLowerLeftPointY(const uint32_t &_value) { std::get< 2>(values_) = _value; }
        inline const uint32_t &getLowerRightPointX() const { return std::get< 3>(values_); }
        inline void setLowerRightPointX(const uint32_t &_value) { std::get< 3>(values_) = _value; }
        inline const uint32_t &getLowerRightPointY() const { return std::get< 4>(values_); }
        inline void setLowerRightPointY(const uint32_t &_value) { std::get< 4>(values_) = _value; }
        inline const uint32_t &getIntersectionPointX() const { return std::get< 5>(values_); }
        inline void setIntersectionPointX(const uint32_t &_value) { std::get< 5>(values_) = _value; }
        inline const uint32_t &getIntersectionPointY() const { return std::get< 6>(values_); }
        inline void setIntersectionPointY(const uint32_t &_value) { std::get< 6>(values_) = _value; }
        inline bool operator==(const LaneType& _other) const {
        return (getFrameId() == _other.getFrameId() && getLowerLeftPointX() == _other.getLowerLeftPointX() && getLowerLeftPointY() == _other.getLowerLeftPointY() && getLowerRightPointX() == _other.getLowerRightPointX() && getLowerRightPointY() == _other.getLowerRightPointY() && getIntersectionPointX() == _other.getIntersectionPointX() && getIntersectionPointY() == _other.getIntersectionPointY());
        }
        inline bool operator!=(const LaneType &_other) const {
            return !((*this) == _other);
        }
    
    };
};

const char* IDrivingLane::getInterface() {
    return ("genivi.aasr.showcase.IDrivingLane:v1_0");
}

CommonAPI::Version IDrivingLane::getInterfaceVersion() {
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

#endif // V1_GENIVI_AASR_SHOWCASE_I_DRIVING_LANE_HPP_
