/*** token.h -- tokeniser specs and stuff
 *
 * Copyright (C) 2011-2012 Sebastian Freundt
 *
 * Author:  Sebastian Freundt <freundt@ga-group.nl>
 *
 * This file is part of dateutils.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the author nor the names of any contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **/
#if !defined INCLUDED_token_h_
#define INCLUDED_token_h_

#if defined __cplusplus
extern "C" {
#endif	/* __cplusplus */

/* spec tokeniser, spec flags plus modifiers and stuff */
typedef enum {
	DT_SPFL_UNK,

	/* generic dt standard */
	DT_SPFL_N_STD,

	/* date specs */
	/* %F, but generally stands for calendar's standard format */
	DT_SPFL_N_DSTD,
	DT_SPFL_N_DFIRST = DT_SPFL_N_DSTD,
	/* year count, consecutive, %Y */
	DT_SPFL_N_YEAR,
	/* month count within the year, recurring, %m */
	DT_SPFL_N_MON,
	/* day count within the week, for 4-level calendars (%w) */
	DT_SPFL_N_DCNT_WEEK,
	/* day count within the month, %d */
	DT_SPFL_N_DCNT_MON,
	/* day count within the year, %D */
	DT_SPFL_N_DCNT_YEAR,
	/* week count within the month, %c */
	DT_SPFL_N_WCNT_MON,
	/* week count within the year, %C */
	DT_SPFL_N_WCNT_YEAR,
	DT_SPFL_N_QTR,
	DT_SPFL_N_LAST = DT_SPFL_N_QTR,

	DT_SPFL_S_WDAY,
	DT_SPFL_S_DFIRST = DT_SPFL_S_WDAY,
	DT_SPFL_S_MON,
	DT_SPFL_S_QTR,
	DT_SPFL_S_DLAST = DT_SPFL_S_QTR,

	/* time specs */
	DT_SPFL_N_SEC,
	DT_SPFL_N_TFIRST = DT_SPFL_N_SEC,
	DT_SPFL_N_MIN,
	DT_SPFL_N_HOUR,
	/* %T, but generally stands for calendar's standard format */
	DT_SPFL_N_TSTD,
	/* %N nanoseconds, non-standard */
	DT_SPFL_N_NANO,
	/* %s epoch spec, non-standard */
	DT_SPFL_N_EPOCH,
	DT_SPFL_N_TLAST = DT_SPFL_N_EPOCH,

	DT_SPFL_S_AMPM,
	DT_SPFL_S_TFIRST = DT_SPFL_S_AMPM,
	DT_SPFL_S_TLAST = DT_SPFL_S_AMPM,

	DT_SPFL_LIT_PERCENT,
	DT_SPFL_LIT_TAB,
	DT_SPFL_LIT_NL,
} dt_spfl_t;

struct dt_spec_s {
	struct {
		/* ordinal flag, 01, 02, 03 -> 1st 2nd 3rd */
		unsigned int ord:1;
		/* roman numeral flag */
		unsigned int rom:1;
		/* controls abbreviation */
		enum {
			DT_SPMOD_NORM,
			DT_SPMOD_ABBR,
			DT_SPMOD_LONG,
			DT_SPMOD_ILL,
		} abbr:2;
		/* for directions a(fter 0)/b(efore 1) */
		unsigned int ab:1;
		/* bizda */
		unsigned int bizda:1;

		/** time specs */
		/* long/short 24h v 12h scale */
		unsigned int sc12:1;
		/* capitalise am/pm indicator */
		unsigned int cap:1;

		/* week-count conventions */
		unsigned int cnt_weeks_iso:1;
		unsigned int cnt_wdays_from:1;

		/* pad to the next word */
		unsigned int:6;
	};
	dt_spfl_t spfl:8;
};

#if !defined BIZDA_AFTER
# define BIZDA_AFTER	(0U)/*>*/
#endif	/* !BIZDA_AFTER */
#if !defined BIZDA_BEFORE
# define BIZDA_BEFORE	(1U)/*<*/
#endif	/* !BIZDA_BEFORE */


static inline struct dt_spec_s
__attribute__((pure, const))
spec_initialiser(void)
{
	struct dt_spec_s res = {{0}, DT_SPFL_UNK};
	return res;
}

#if defined __cplusplus
}
#endif	/* __cplusplus */

#endif	/* INCLUDED_token_h_ */
