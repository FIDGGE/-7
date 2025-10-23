/***********************
 *Автор: Гончаров Роман*
 *Вариант: 4           *
 ***********************/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main() {
  string filename = "cubes.txt";
  ifstream file(filename);
  
  if (!file.is_open()) {
    cout << "Error opening file!" << endl;
    return 1;
  }
  
  int cubeId;
  string cubeColor, targetColor;
  double edgeLength, cubeVolume;
  
  double totalVolume = 0;
  double maxVolume = 0, minVolume = numeric_limits<double>::max();
  int maxId, minId;
  string maxColor, minColor;
  double maxEdge, minEdge;
  bool colorFound = false;
  
  cout << "Enter color to search: ";
  cin >> targetColor;
  cout << "\nCubes of color '" << targetColor << "':\n";
  
  while (file >> cubeId >> cubeColor >> edgeLength) {
    cubeVolume = edgeLength * edgeLength * edgeLength;
    
    if (cubeColor == targetColor) {
      cout << "  ID: " << cubeId << ", Edge: " << edgeLength 
           << " cm, Volume: " << cubeVolume << " cm³\n";
      totalVolume += cubeVolume;
      colorFound = true;
    }
    
    if (cubeVolume > maxVolume) {
      maxVolume = cubeVolume;
      maxId = cubeId;
      maxColor = cubeColor;
      maxEdge = edgeLength;
    }
    
    if (cubeVolume < minVolume) {
      minVolume = cubeVolume;
      minId = cubeId;
      minColor = cubeColor;
      minEdge = edgeLength;
    }
  }
  
  file.close();
  
  cout << (colorFound ? "Total volume: " + to_string(totalVolume) + " cm³\n" : "No cubes found\n");
  cout << "\nCube with maximum volume:\n  ID: " << maxId << ", Color: " << maxColor 
       << ", Edge: " << maxEdge << " cm, Volume: " << maxVolume << " cm³\n";
  cout << "Cube with minimum volume:\n  ID: " << minId << ", Color: " << minColor 
       << ", Edge: " << minEdge << " cm, Volume: " << minVolume << " cm³\n";
  
  return 0;
}
