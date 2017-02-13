#ifndef BITMATH_H_
#define BITMATH_H_

// set n'th bit to x
int setBitTo(int number, int n, int x){
	number^=(-x^number)&(1<<n);
	return number;
}

// clear n'th bit (set it to 0)
int clearBit(int number, int n){
	number &=~(1<<n);
	return number;
}

//void clearBit(int * number, int n){
	//*number &=~(1<<n);
//}

int setBit(int number, int n){
	number|=1<<n;
	return number;
}

int checkBit(int number, int n){
	int bit = (number>>n)&1;
	return bit;
}

#endif /* BITMATH_H_ */