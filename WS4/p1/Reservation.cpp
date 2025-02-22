//#define _CRT_SECURE_NO_WARNINGS
//#include "Reservation.h"
//#include <sstream>
//#include <algorithm>
//#include <cstring>
//
//namespace seneca {
//
//    Reservation::Reservation() : reservation_id{ "" }, name(""), email(""), party_size(0), day(0), hour(0) {}
//
//    Reservation::Reservation(const std::string& res) {
//        std::string clean_res = res;
//        clean_res.erase(std::remove_if(clean_res.begin(), clean_res.end(), ::isspace), clean_res.end());
//
//        std::istringstream iss(clean_res);
//        std::string token;
//
//        std::getline(iss, token, ':');
//        strncpy(reservation_id, token.c_str(), sizeof(reservation_id) - 1);
//        reservation_id[sizeof(reservation_id) - 1] = '\0';
//
//        std::getline(iss, name, ',');
//        std::getline(iss, email, ',');
//        std::getline(iss, token, ',');
//        party_size = std::stoi(token);
//        std::getline(iss, token, ',');
//        day = std::stoi(token);
//        std::getline(iss, token, ',');
//        hour = std::stoi(token);
//    }
//
//    void Reservation::update(int new_day, int new_hour) {
//        day = new_day;
//        hour = new_hour;
//    }
//        
//    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
//        os << "Reservation " << std::setw(10) << std::right << res.reservation_id << ": "
//            << std::setw(20) << std::right << res.name << "  <" << std::left << res.email << ">";
//
//        int email_padding = 21 - res.email.length();
//        for (int i = 0; i < email_padding; ++i) {
//            os << " ";
//        }
//
//        os << " ";
//
//        if (res.hour >= 6 && res.hour <= 9) {
//            os << "Breakfast on day " << res.day << " @ " << res.hour << ":00 for " << res.party_size << (res.party_size == 1 ? " person." : " people.");
//        }
//        else if (res.hour >= 11 && res.hour <= 15) {
//            os << "Lunch on day " << res.day << " @ " << res.hour << ":00 for " << res.party_size << (res.party_size == 1 ? " person." : " people.");
//        }
//        else if (res.hour >= 17 && res.hour <= 21) {
//            os << "Dinner on day " << res.day << " @ " << res.hour << ":00 for " << res.party_size << (res.party_size == 1 ? " person." : " people.");
//        }
//        else {
//            os << "Drinks on day " << res.day << " @ " << res.hour << ":00 for " << res.party_size << (res.party_size == 1 ? " person." : " people.");
//        }
//        os << std::endl;
//
//        return os;
//    }
//
//} // namespace seneca


#define _CRT_SECURE_NO_WARNINGS
#include "Reservation.h"
#include <sstream>
#include <algorithm>
#include <cstring>

namespace seneca {

    Reservation::Reservation() : reservation_id{ "" }, name(""), email(""), party_size(0), day(0), hour(0) {}

    Reservation::Reservation(const std::string& res) {
        std::string clean_res = res;

        std::istringstream iss(clean_res);
        std::string token;

        // Lấy ID của đặt chỗ
        std::getline(iss, token, ':');
        // Xóa khoảng trắng đầu và cuối nhưng giữ khoảng trắng giữa các từ
        token.erase(0, token.find_first_not_of(' '));
        token.erase(token.find_last_not_of(' ') + 1);
        strncpy(reservation_id, token.c_str(), sizeof(reservation_id) - 1);
        reservation_id[sizeof(reservation_id) - 1] = '\0';

        // Lấy tên người đặt chỗ
        std::getline(iss, name, ',');
        // Xóa các khoảng trắng đầu và cuối của tên
        name.erase(name.find_last_not_of(' ') + 1);
        name.erase(0, name.find_first_not_of(' '));

        // Lấy email người đặt chỗ
        std::getline(iss, email, ',');
        // Xóa các khoảng trắng đầu và cuối của email
        email.erase(email.find_last_not_of(' ') + 1);
        email.erase(0, email.find_first_not_of(' '));

        // Lấy số lượng người tham gia
        std::getline(iss, token, ',');
        party_size = std::stoi(token);

        // Lấy ngày đặt chỗ
        std::getline(iss, token, ',');
        day = std::stoi(token);

        // Lấy giờ đặt chỗ
        std::getline(iss, token, ',');
        hour = std::stoi(token);
    }

    void Reservation::update(int new_day, int new_hour) {
        day = new_day;
        hour = new_hour;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
        // Căn chỉnh ID đặt chỗ đúng cách, không có khoảng trắng trước dấu ":"
        os << "Reservation " << std::setw(10) << std::right << res.reservation_id << ": "
            << std::setw(20) << std::right << res.name << "  <" << std::left << res.email << "> ";

        // Tính toán và thêm khoảng trắng sau email để căn chỉnh đúng cách
        int email_padding = 20 - res.email.length();
        for (int i = 0; i < email_padding; ++i) {
            os << " ";
        }

        os << " ";

        // Xuất thông tin chi tiết về thời gian đặt chỗ và số lượng người
        if (res.hour >= 6 && res.hour <= 9) {
            os << "Breakfast on day " << res.day << " @ " << res.hour << ":00 for " << res.party_size << (res.party_size == 1 ? " person." : " people.");
        }
        else if (res.hour >= 11 && res.hour <= 15) {
            os << "Lunch on day " << res.day << " @ " << res.hour << ":00 for " << res.party_size << (res.party_size == 1 ? " person." : " people.");
        }
        else if (res.hour >= 17 && res.hour <= 21) {
            os << "Dinner on day " << res.day << " @ " << res.hour << ":00 for " << res.party_size << (res.party_size == 1 ? " person." : " people.");
        }
        else {
            os << "Drinks on day " << res.day << " @ " << res.hour << ":00 for " << res.party_size << (res.party_size == 1 ? " person." : " people.");
        }
        os << std::endl;

        return os;
    }

} // namespace seneca
