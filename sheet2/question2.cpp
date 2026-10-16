#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    float x, y, z;
};

class Point_3D {
    private:
        Point P[30];
        float N[30];
        int m;

    public:
        void readData() {
            cout << "Enter number of points (max 30): ";
            cin >> m;
            if (m > 30) m = 30;
            
            for (int i = 0; i < m; i++) {
                cout << "Enter x, y, z for point " << i + 1 << ": ";
                cin >> P[i].x >> P[i].y >> P[i].z;
                N[i] = sqrt(pow(P[i].x, 2) + pow(P[i].y, 2) + pow(P[i].z, 2));
            }
        }

        float getFirstLastDistance() {
            if (m < 2) return 0; 
            
            Point first = P[0];
            Point last = P[m - 1];
            
            return sqrt(pow(last.x - first.x, 2) + pow(last.y - first.y, 2) + pow(last.z - first.z, 2));
        }

        float getMaxNorm() {
            if (m == 0) return 0;
            float maxVal = N[0];
            for (int i = 1; i < m; i++) {
                if (N[i] > maxVal) {
                    maxVal = N[i];
                }
            }
            return maxVal;
        }

        Point_3D compareMaxNorm(Point_3D otherObj) {
            if (this->getMaxNorm() > otherObj.getMaxNorm()) {
                return *this; 
            } else {
                return otherObj; 
            }
        }

        float getMinDistance(Point_3D otherObj) {
            float dist1 = this->getFirstLastDistance();
            float dist2 = otherObj.getFirstLastDistance();
            
            if (dist1 < dist2) {
                return dist1;
            } else {
                return dist2;
            }
        }

        void display() {
            cout << "X\tY\tZ\tNorm (N)\n";
            cout << "--------------------------------\n";
            for (int i = 0; i < m; i++) {
                cout << P[i].x << "\t" << P[i].y << "\t" << P[i].z << "\t" << N[i] << "\n";
            }
        }
};

int main() {
    Point_3D obj1, obj2;
    
    cout << "--- Enter Data for Object 1 ---\n";
    obj1.readData();
    
    cout << "\n--- Enter Data for Object 2 ---\n";
    obj2.readData();
    
    cout << "\n--- Object 1 Table ---\n";
    obj1.display();
    cout << "\n--- Object 2 Table ---\n";
    obj2.display();
    
    cout << "\nDistance (First to Last) - Object 1: " << obj1.getFirstLastDistance() << "\n";
    cout << "Distance (First to Last) - Object 2: " << obj2.getFirstLastDistance() << "\n";
    
    cout << "Max Norm - Object 1: " << obj1.getMaxNorm() << "\n";
    cout << "Max Norm - Object 2: " << obj2.getMaxNorm() << "\n";
    
    cout << "\nComparing objects for the highest norm...\n";
    Point_3D winnerObj = obj1.compareMaxNorm(obj2);
    cout << "The object with the highest norm contains this data:\n";
    winnerObj.display();
    
    cout << "\nThe minimum First-Last distance out of the two objects is: " 
         << obj1.getMinDistance(obj2) << "\n";

    return 0;
}
