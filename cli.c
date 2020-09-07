#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include <stdbool.h>
#include "trip.h"

#if DEV == 0
const char *argp_program_version = "Version of tripcode: 0.2";
const char *argp_program_bug_address = "<shichuang@horsefucker.org>";
static char doc[] = "Maining tripcodes by pattern, count and case sensitivity";
static char args_doc[] = "";
static struct argp_option options[] = { 
	{ "match", 'm', "PATTERN", 0, "Pattern for match tripcodes."},
	{ "count", 'c', "NUMBER", 0, "Number of getting tripcodes."},
	{ "nocase",'i', 0, OPTION_ARG_OPTIONAL, "Ignor case for matched tripcodes"},
	{ 0 } 
};

struct arguments {
	char *match_str;
	int count;
	bool caseIgnor;
	uint8_t req;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
	struct arguments *arguments = state->input;
	switch (key) {
		case 'm': arguments->match_str = arg; arguments->req += 1; break;
		case 'c': arguments->count = atoi(arg);  arguments->req += 1; break;
		case 'i': arguments->caseIgnor = true; break;
		case ARGP_KEY_ARG: return 0;
		case ARGP_KEY_END:
		   if (arguments->req < 2) {
			   argp_usage(state);
			   printf("Too few arguments!\n");
		   }
		default: return ARGP_ERR_UNKNOWN;
	}   
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };
#endif

int main(int argc, char *argv[]) {
	uint32_t seed;
	
	char *match;
	uint16_t count;
	bool ignor;

#if DEV == 0
	struct arguments arguments;

    arguments.caseIgnor = false;
    arguments.req = 0;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);	

	match = arguments.match_str;
	count = arguments.count;
	ignor = arguments.caseIgnor;

	seed = time(0);
#else
	match = "cov"; count = 100; ignor = 0; seed = 1591235563;
#endif

	srand(seed);
	printf("Seed is %d\n", seed);
	
	uint8_t len = 8;
	char buf[10], seq[len];
	uint32_t iter = 0;
	while(count) {
		iter++;
		gener_seq(seq, len);
		encode_tripcode(seq, buf);
		if(compare_trips(buf, match, ignor)) {
			printf("Pass: %s\tTrip: !%s\n", seq, buf);
			count--;
		}
	}
	printf("Iteration: %d\n", iter);
}

