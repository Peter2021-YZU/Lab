#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    int x;
    int y;
    int numbercases;
    int Cases_Counter = 0;



    int Abs_LinePoint1; // Abs is for abcissa of point
    int Ord_LinePoint1; // Ord is for Ordonate of point
    int Abs_LinePoint2;
    int Ord_LinePoint2;
    int Abs_SegmentPoint1;
    int Ord_SegmentPoint1;
    int Abs_SegmentPoint2;
    int Ord_SegmentPoint2;




    cin >> numbercases;
    while (Cases_Counter < numbercases){
        for(int counter = 0; counter < 4; counter++){
            cin >> x >> y;

            if (counter == 0){
                Abs_LinePoint1 = x;
                Ord_LinePoint1 = y;
            }
            else if(counter == 1){
                Abs_LinePoint2 = x;
                Ord_LinePoint2 = y;
            }
            else if (counter == 2){
                Abs_SegmentPoint1 = x;
                Ord_SegmentPoint1 = y;
            }
            else if (counter == 3){
                Abs_SegmentPoint2 = x;
                Ord_SegmentPoint2 = y;
            }
        }
        // find the function of the Line
        double Ord_Direcion = Ord_LinePoint2 - Ord_LinePoint1;
        double Abs_Direction = Abs_LinePoint1 - Abs_LinePoint2;
        double Line_Function = Ord_Direcion*Abs_LinePoint1 + Abs_Direction*Ord_LinePoint1;

        // Verify if the segment and the Line intersect
        double SegPoint1_Dir = Ord_Direcion*Abs_SegmentPoint1 + Abs_Direction*Ord_SegmentPoint1;
        double SegPoint2_Dir = Ord_Direcion*Abs_SegmentPoint2 + Abs_Direction*Ord_SegmentPoint2;


        if(SegPoint1_Dir == Line_Function && SegPoint2_Dir == Line_Function){
            cout << "Yes, the line segment is on the line" << endl;
        }
        else if ((SegPoint1_Dir <= Line_Function && SegPoint2_Dir >= Line_Function) || (SegPoint1_Dir >= Line_Function && SegPoint2_Dir <= Line_Function)){
            double Seg_OrdDirec = Ord_SegmentPoint2 - Ord_SegmentPoint1;
            double Seg_AbsDirec= Abs_SegmentPoint1 - Abs_SegmentPoint2;
            double Seg_Function = Seg_OrdDirec*Abs_SegmentPoint1 + Seg_AbsDirec*Ord_SegmentPoint1;
            double Denominator = Ord_Direcion*Seg_AbsDirec - Seg_OrdDirec*Abs_Direction;

            double Abs_Intersect = (Seg_AbsDirec*Line_Function - Abs_Direction*Seg_Function)/Denominator;
            double Ord_Intersect = (Ord_Direcion*Seg_Function - Seg_OrdDirec*Line_Function)/Denominator;

            cout << "yes" << " " << fixed << setprecision(8) << Abs_Intersect << " " << fixed << setprecision(8) << Ord_Intersect << endl;
        }
        else{

            cout << "no" << endl;
        }

        Cases_Counter++;
    }
    cout << "Gabriela Mayte Souza Pinedo 1093550" << endl;

    return 0;
}
