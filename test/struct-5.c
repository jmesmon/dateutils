#include "dt-core.h"

int
main(void)
{
	struct dt_dt_s dt;

	dt.neg = 0;
	dt.dur = 0;
	dt.typ = DT_SEXY;
	if (dt.d.typ != DT_SEXY || dt.d.neg || dt.d.dur) {
		return 1;
	}

	dt_make_sandwich(&dt, DT_DUNK, DT_TUNK);
	if (!dt.sandwich || dt.d.neg || dt.d.dur) {
		return 1;
	}
	return 0;
}

/* struct-5.c ends here */
