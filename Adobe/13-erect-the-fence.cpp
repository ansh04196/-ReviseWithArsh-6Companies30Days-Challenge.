class Solution 
{
public:
    using Point = vector<int>;

    // Custom comparator to sort points based on x-coordinates and then y-coordinates
    static bool comparePoints(Point& a, Point& b) 
    {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }

    vector<Point> outerTrees(vector<Point>& trees) 
    {
        auto crossProduct = [](Point& B, Point& A, Point& T) -> int
        {
            return (T[1] - B[1]) * (B[0] - A[0]) - (B[1] - A[1]) * (T[0] - B[0]);
        };

        // Sorting the trees based on x-coordinates and then y-coordinates
        sort(trees.begin(), trees.end(), comparePoints);

        deque<Point> convexHull;

        for (Point currentPoint : trees)
        {
            // Keep removing points from the back of deque if they form a right turn
            while (convexHull.size() >= 2 && crossProduct(convexHull.back(), convexHull[convexHull.size() - 2], currentPoint) < 0)
                convexHull.pop_back();
            convexHull.push_back(currentPoint);

            // Keep removing points from the front of deque if they form a right turn
            while (convexHull.size() >= 2 && crossProduct(convexHull[0], convexHull[1], currentPoint) > 0)
                convexHull.pop_front();
            convexHull.push_front(currentPoint);
        }

        // Convert deque to set to eliminate duplicates
        set<Point> uniquePoints(convexHull.begin(), convexHull.end());
        // Convert set back to vector to return the result
        return vector<Point>(uniquePoints.begin(), uniquePoints.end());
    }
};
