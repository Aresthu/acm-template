unsigned int hash(char *st, int mod)
{
    unsigned int n=0;
    char *b = (char*) &n;
    while (*st) b[i%4] ^= *(st++);
    return n % mod;
}

unsigned int ELF_Hash(char *st, int mod)
{
    unsigned int g, h=0;
    while (*st)
    {
        h = (h<<4) + *(st++);
        g = h & 0xF0000000;
        if (g) h ^= g>>24;
        h &= ~g;
    }
    return h % mod;
}
