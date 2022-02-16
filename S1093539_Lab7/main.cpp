#include <iostream>

using namespace std;


int main()
{

    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int x4;
    int y4;
    int counter = 0;
    int numbinput;


    cin >> numbinput;
    while(counter < numbinput){
        counter++;


        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        int BottomLeft1[2] = {x1,y1};
        int TopRight1[2] = {x2,y2};
        int BottomLeft2[2] = {x3, y3};
        int TopRight2[2] = {x4, y4};



        if (BottomLeft1[1] > TopRight2[1] || TopRight1[1] < BottomLeft2[1] || BottomLeft2[0] > TopRight1[0] || TopRight2[0] < BottomLeft1[0])
            cout << "no" << '\n';
        else{
            cout << "yes" << " ";

            int numbvertices1 = 0;
            int numbvertices2 = 0;

            // count the number of R2's vertices in side R1 or on the edges of R1
            if ((BottomLeft1[0] <= BottomLeft2[0]) && (BottomLeft1[1] <= BottomLeft2[1]))
                numbvertices2++;
            if ((BottomLeft2[0] >= BottomLeft1[0]) && (TopRight2[1] <= TopRight1[1]))
                numbvertices2++;
            if ((TopRight2[0] <= TopRight1[0]) && (TopRight2[1] <= TopRight1[1]))
                numbvertices2++;
            if ((TopRight2[0] <= TopRight1[0]) && (BottomLeft2[1] >= BottomLeft1[1]))
                numbvertices2++;


            // count the number of R1's vertices in side R2 or on the edges of R2
            if ((BottomLeft2[0] <= BottomLeft1[0]) && (BottomLeft2[1] <= BottomLeft1[1]))
                numbvertices1++;
            if ((BottomLeft1[0] >= BottomLeft2[0]) && (TopRight1[1] <= TopRight2[1]))
                numbvertices1++;
            if ((TopRight1[0] <= TopRight2[0]) && (TopRight1[1] <= TopRight2[1]))
                numbvertices1++;
            if ((TopRight1[0] <= TopRight2[0]) && (BottomLeft1[1] >= BottomLeft2[1]))
                numbvertices1++;

            cout << numbvertices1 << " " << numbvertices2 << endl;
            numbvertices1 =0;
            numbvertices2 = 0;
        }

    }
    return 0;
}
