#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>


using namespace std;


struct Diver{
	
	void dataStorage(float sa, float sb, float sc, float sd, float se, float sf, float sg, float sh, float si, float sj){
	
		vector <float> scores={sa,sb,sc,sd,se,sf,sg,sh,si,sj};
		
		std::sort(scores.begin(),scores.end());
	}

	

	
	
	
	
};



int main() {

	ifstream readFile("m7dive.txt");
	ofstream writeFile("mp7output.txt");
	
	Diver currentDiver;
	float a,b,c,d,e,f,g,h,i,j;
	string diverName;
	int count{0};
	
	while(readFile >> diverName >> a >> b >> c >> d >> e >> f >> g >> h >> i>> j){
	
		currentDiver.dataStorage(a,b,c,d,e,f,g,h,i,j);
		
		diverName.resize(15);
		writeFile << diverName  << fixed << setprecision (1);
		writeFile << a << "\t" << b << "\t" << c << "\t"  << d << "\t" <<e << "\t" << f << "\t" << g << "\t" <<h << "\t"  << i << "\t" << j << endl;
	
		
	
		
		
	++count;
	}
	
		
	return 0;
}
