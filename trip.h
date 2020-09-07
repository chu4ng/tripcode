#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h> 
#include <stdint.h>
#include <stdbool.h>

#define DEV 0

static char alph[] = {'!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}'};
static uint8_t alph_l = sizeof(alph);

// Alph for replacement bad characters
static char alph_s1[] = ":;<=>?@[\\]^_`-,|+(){}\"'%&$!#*";
static char alph_s2[] = "ABCDEFGabcdef................";

void encode_tripcode(char *pattern, char *buf_str);
bool compare_trips(const char *current_code, const char *match, bool ignore_flag);
// Generate random sequence
void gener_seq(char *buf_str, uint8_t len);
