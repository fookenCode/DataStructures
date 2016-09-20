#ifndef _PARAMS_H_
#define _PARAMS_H_

class Params {
public:
	int nTotal;
	int returnAddress;

	Params(int n, int ra) : nTotal(n), returnAddress(ra) { }
};
#endif //_PARAMS_H_