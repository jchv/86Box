#include <cstdio>
#include <cstdint>
#include "../../plat.h"
#include "../../ui.h"
#include "../../mouse.h"


int dopause, doresize, quited, mouse_capture;
uint64_t timer_freq;
int infocus;
char emu_version[128];
int rctrl_is_lalt;
int update_icons;


int ui_msgbox(int type, void *arg) {
    return 0;
}

void ui_check_menu_item(int id, int checked) {
}

wchar_t  *ui_window_title(wchar_t *s) {
    return s;
}

void ui_status_update() {
}

int ui_sb_find_part(int tag) {
    return 0;
}

void ui_sb_update_panes() {
}

void ui_sb_update_tip(int meaning) {
}

void ui_sb_check_menu_item(int tag, int id, int chk) {
}

void ui_sb_enable_menu_item(int tag, int id, int val) {
}

void ui_sb_update_icon(int tag, int val) {
}

void ui_sb_update_icon_state(int tag, int active) {
}

void ui_sb_set_text_w(wchar_t *wstr) {
}

void ui_sb_set_text(char *str) {
}

void ui_sb_bugui(char *str) {
}

void ui_sb_mount_floppy_img(uint8_t id, int part, uint8_t wp, wchar_t *file_name) {
}

void ui_sb_mount_zip_img(uint8_t id, int part, uint8_t wp, wchar_t *file_name) {
}

void startblit() {
}

void endblit() {
}

void take_screenshot() {
}

extern void set_language(int id) {
}

extern wchar_t *plat_get_string(int id) {
    return const_cast<wchar_t *>(L"");
}

void mouse_poll() {
}
