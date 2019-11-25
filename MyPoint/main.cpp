#include <iostream>
#include <cmath>
using namespace std;
class MyPoint{
	private :
		int mPosX, mPosY;
	public:
		MyPoint(){
			mPosX=1;
			mPosY=1;
		}
		MyPoint(int x,int y){
			mPosX=x;
			mPosY=y;
		}
		void setmPosX(int x){
			mPosX=x;
		}
		int getmPosX(){
			return mPosX;
		}
		void setmPosY(int y){
			mPosY=y;
		}
		int getmPosY(){
			return mPosY;
		}
		void Display (){
			cout<<"Toa do cua diem : ("<<mPosX<<","<<mPosY<<")";
		}
		int Distance(MyPoint P){
			cout<<endl<<"khoang cach den diem la: ";
			double kc=sqrt((mPosX-P.mPosX)*(mPosX-P.mPosX)+(mPosY-P.mPosY)*(mPosY-P.mPosY));
			//return kc;
			cout<<kc<<endl;
		}
	
};

int main(int argc, char** argv) {
	MyPoint p1,p2,p3;
	p1.setmPosX(9);
	p1.setmPosY(3);
	p1.Display();
	cout<<endl<<p1.getmPosX();
	cout<<endl<<p1.getmPosY();
	p2=MyPoint();
	p1.Distance(p2);
	
	return 0;
}
