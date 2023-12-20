

import 'dart:io';
File f = File("DayThreeInput.txt");
List<String> input = f.readAsLinesSync();//.sublist(2,3);
Set<String> symbols = {"-", "#", "=", "*", "+", "@", "\$", "&", "/", "%"};
void main(){
  part1();
  // part2();
  // test();
}

void test(){
  print(input[6][56]);
  print(isSymbol(input[6][56]));
}

bool isNumber(String x){
  for(int c in x.runes){
    //48-57
    if(48 > c || c > 57){
      return false;
    }
  }
  return true;
}

bool isSymbol(String x){
  return symbols.contains(x);
}

bool wasFullNum(String prev, String current){
  if(isNumber(prev)&& !isNumber(current)){
    return true;
  }
  return false;
}

bool isPartNum(int yPos, int si, int vl){
  for(int y = yPos-1; y <= y+1;y++){
    for(int x = si-1;x <si+vl;x++){
      try {
        if(isSymbol(input[y][x])){
          return true;
        }
      } catch (e){}
      
    }
  }
  return false;
}

void part1(){
  List<String> partNumbers = [];
  for(int y = 0; y < input.length;y++){
    String line = input[y];
    // get the full number
    int startIndex = 0;
    int viewLength = 1;
    String prevFocus = ".";
    print("Line Last Index: ${line.length-1}");
    while(startIndex <= line.length){
      print("Looking at: ${line.substring(startIndex,startIndex+viewLength)}");
      if(startIndex+viewLength >= line.length){
        break;
      }
      String focus = line.substring(startIndex,startIndex+viewLength);
      if(wasFullNum(prevFocus, focus) || (isNumber(focus) && (startIndex+viewLength==line.length))){
        if(isPartNum(y, startIndex, viewLength-1)){
          partNumbers.add(prevFocus);
        }
        print("PF: $prevFocus");
        // print("Start index: $startIndex");
        // print("Next Index: ${startIndex+viewLength-1}");
        // print("Next char: ${input[y][startIndex+viewLength-1]}");
        startIndex += viewLength-1;
        viewLength = 1;
      }else if(isNumber(focus)){
        viewLength++;
      }else{
        startIndex++;
      }
      prevFocus = focus;
    }
  }
  int sum = 552835;
  for(String part in partNumbers){
    // print(sum);
    sum += int.parse(part);
  }
  if(sum >= 597851){
    print("too high");
  }else if (sum <= 549041){
    print("too low");
  }else{print(sum);}
}

void part2(){

}
