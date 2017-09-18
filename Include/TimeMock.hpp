#include <ITime.hpp>
#include <gmock/gmock.h>

class TimeMock: public ITime
{
public:
    MOCK_METHOD0(getCurrentTime, std::string());
};

