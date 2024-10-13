#define MAX_PARAMS 26

extern const char *parametros[];

#define parametro_por_letra(letra) (parametros + (letra) - 'A')

extern bool compara_comando(const char *source, const char *padrao);
