#include <iostream>
using namespace std;

int findAngle(int hh, int mm)
{
    hh = hh % 12;
    int h = (hh * 360) / 12 + (mm * 360) / (12 * 60);
    int m = (mm * 360) / (60);

    int angle = abs(h - m);

    if (angle > 180) {
        angle = 360 - angle;
    }

    return angle;
}

int main()
{
    int d;
    cin >> d;
    int cnt=0;
    bool arr[12][60]={};

    for(int i=0; i<=11; i++){
        for(int j=0; j<=59; j+=2){
            if(findAngle(i, j)==d){
                cnt++;
                arr[i][j]=true;
            }
        }
    }


    cout << cnt << endl;
    for(int i=0; i<=11; i++){
        for(int j=0; j<=59; j+=2){
            if(arr[i][j]){
                printf("%02d:%02d\n", i, j);
            }
        }
    }
}