// Passed Moulinette 2019.09.01

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char out = 0;

	out = out | ((octet & 128) >> 7);
	out = out | ((octet & 64) >> 5);
	out = out | ((octet & 32) >> 3);
	out = out | ((octet & 16) >> 1);
	out = out | ((octet & 8) << 1);
	out = out | ((octet & 4) << 3);
	out = out | ((octet & 2) << 5);
	out = out | ((octet & 1) << 7);
	return (out);
}

#if 0
//reverse the byte
byte = 8 bit
byte = 1010 1010


0000 0001   = 1
0000 0010   = 2
0000 0100   = 4
0000 1000   = 8
0001 0000   = 16
0010 0000   = 32
0100 0000   = 64
1000 0000   = 128


1 0 1 0   1 0 1 1
0 0 0 0   0 0 0 1   num = 1;

0000 0001 << 7
1000 0000 
10


