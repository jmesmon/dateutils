#include <stdio.h>
#include "dt-core.h"

int
main(void)
{
	int res = 0;
#if !defined __uint128_t_defined
	typedef struct {
		uint64_t l;
		uint64_t h;
	} uint128_t;
#endif	/* !uint128_t */

#define CHECK_SIZE(x, y)						\
	if (sizeof(x) != sizeof(y)) {					\
		fprintf(stderr, "sizeof(" #x ") -> %zu\n", sizeof(x));	\
		res = 1;						\
	}

	CHECK_SIZE(struct dt_dt_s, uint128_t);
	CHECK_SIZE(struct dt_d_s, uint64_t);
	CHECK_SIZE(struct dt_t_s, uint64_t);
	CHECK_SIZE(dt_ymdhms_t, uint64_t);
	CHECK_SIZE(dt_sexy_t, uint64_t);
	return res;
}

/* struct-7.c ends here */
