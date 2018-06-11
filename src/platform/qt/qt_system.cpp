#include <cstdio>
#include <cstdint>
#include "../../plat.h"
#include "../../plat_dynld.h"

wchar_t	*fix_exe_path(wchar_t *str) {
    return str;
}

FILE *plat_fopen(wchar_t *path, wchar_t *mode) {
}

void plat_remove(wchar_t *path) {
}

int plat_getcwd(wchar_t *bufp, int max) {
    return 0;
}

int plat_chdir(wchar_t *path) {
    return 0;
}

void plat_get_exe_name(wchar_t *s, int size) {
}

wchar_t *plat_get_filename(wchar_t *s) {
    return s;
}

wchar_t *plat_get_extension(wchar_t *s) {
    return s;
}

void plat_append_filename(wchar_t *dest, wchar_t *s1, wchar_t *s2) {
}

void plat_put_backslash(wchar_t *s) {
}

void plat_path_slash(wchar_t *path) {
}

int plat_path_abs(wchar_t *path) {
    return 0;
}

int plat_dir_check(wchar_t *path) {
    return 0;
}

int plat_dir_create(wchar_t *path) {
    return 0;
}

uint64_t plat_timer_read() {
    return 0;
}

uint32_t plat_get_ticks() {
    return 0;
}

void plat_delay_ms(uint32_t count) {
}

void plat_pause(int p) {
}

void plat_mouse_capture(int on) {
}

int plat_vidapi(char *name) {
    return 0;
}

char *plat_vidapi_name(int api) {
    return const_cast<char *>("");
}

int plat_setvid(int api) {
    return 0;
}

void plat_vidsize(int x, int y) {
}

void plat_setfullscreen(int on) {
}

void plat_resize(int x, int y) {
}

void *dynld_module(const char *name, dllimp_t *table) {
    return nullptr;
}
