class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>> reservedRows;

        for (auto seat : reservedSeats) {
            reservedRows[seat[0]].push_back(seat[1]);
        }

        int emptyRowsGroups = (n - reservedRows.size()) * 2;
        int groupsInReservedRows = 0;

        for (auto seat : reservedRows) {
            vector<int> seatsBooked(11, 0);

            for (int x : seat.second) {
                seatsBooked[x] = 1;
            }

            if (!seatsBooked[2] && !seatsBooked[3] && !seatsBooked[4] && !seatsBooked[5]) {
                groupsInReservedRows++;
                seatsBooked[5] = 1;
            }

            if (!seatsBooked[6] && !seatsBooked[7] && !seatsBooked[8] && !seatsBooked[9]) {
                groupsInReservedRows++;
                seatsBooked[6] = 1;
            }

            if (!seatsBooked[4] && !seatsBooked[5] && !seatsBooked[6] && !seatsBooked[7]) {
                groupsInReservedRows++;
            }
        }

        return (emptyRowsGroups + groupsInReservedRows);
    }
};
