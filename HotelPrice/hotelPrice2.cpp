 

#include <iostream>
#include <vector>

using namespace std;

class HotelRoom {
public:
    HotelRoom(int bedrooms, int bathrooms) 
    : bedrooms_(bedrooms), bathrooms_(bathrooms) {}
    
    int get_price() {
        return 50*bedrooms_ + 100*bathrooms_;
    }
private:
    int bedrooms_;
    int bathrooms_;
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms, bathrooms) {}

    int get_price() {
        return HotelRoom::get_price() + 100;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> rooms;
    for (int i = 0; i < n; ++i) {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            HotelRoom* std_hotel=  new HotelRoom(bedrooms,bathrooms);
            rooms.push_back(std_hotel->get_price());
        } else {
             HotelApartment* aprtment_hotel=  new HotelApartment(bedrooms,bathrooms);
            rooms.push_back(aprtment_hotel->get_price());
        }
    }

    int total_profit = 0;
    for (int room : rooms) {
        total_profit += room;
    }
    cout << total_profit << endl;

    
    rooms.clear();

    return 0;
}

