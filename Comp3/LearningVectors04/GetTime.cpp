#include "GetTime.h"

std::string get_file_timestamp()
{
    const auto now = std::chrono::system_clock::now();
    const auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream output_stream;

    struct tm time_info;
    const auto errno_value = localtime_s(&time_info, &in_time_t);
    if (errno_value != 0)
    {
        throw std::runtime_error("localtime_s() failed: " + std::to_string(errno_value));
    }

    output_stream << std::put_time(&time_info, "%Y-%m-%d.%H_%M_%S");
    return output_stream.str();
}