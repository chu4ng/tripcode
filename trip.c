#include "trip.h"


void encode_tripcode(char *pattern, char *buffer) {
	char buf_salt[3];
	strncpy(buf_salt, pattern+1, 2);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < strlen(alph_s1); j++)
			if(buf_salt[i] == alph_s1[j]) {
				buf_salt[i] = alph_s2[j];
			}
	}
	buf_salt[2] = '\0';

	char *trip_buffer = crypt(pattern, buf_salt);
	strncpy(buffer, trip_buffer+(strlen(trip_buffer)-10), 10);
}
bool compare_trips(const char *trip, const char *match, bool ignore) {
	char *p;
	if(!ignore)
		p = (char *)strstr(trip, match);
	else 
		p = strcasestr(trip, match);
	return (p) ? 1 : 0;
}
void gener_seq(char *buffer, uint8_t len) {
	for(uint8_t i = 0; i < len; i++)
		buffer[i] = alph[rand() % alph_l];
	buffer[len-1] = '\0';
}
