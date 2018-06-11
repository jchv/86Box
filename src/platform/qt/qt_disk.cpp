#include <cstdio>
#include <cstdint>
#include "../../plat.h"


uint8_t	host_cdrom_drive_available[26];
uint8_t	host_cdrom_drive_available_num;


void cdrom_eject(uint8_t id) {
}

void cdrom_reload(uint8_t id) {
}

void zip_eject(uint8_t id) {
}

void zip_reload(uint8_t id) {
}

int ioctl_open(uint8_t id, char d) {
}

void ioctl_reset(uint8_t id) {
}

void ioctl_close(uint8_t id) {
}
