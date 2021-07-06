#include <stdio.h>
#include <iostream>

#include "Smurf.h"

int Smurf::compareAlpha(Smurf aSmurf) {
	if (_name > aSmurf._name) {
		return 1;
	}
	else if (_name < aSmurf._name) {
		return -1;
	}
	else {
		return 0;
	}
}
