#include "EnOceanUtils.h"

namespace EnOcean {

void hexStringToByteArray(std::string stringInput, byte* output, uint8_t byteLength) {
  for (uint8_t i = 0; i < byteLength; i++) {
    output[i] = strtol(stringInput.substr(i * 2, 2).c_str(), NULL, 16);
  }
}

void printBuffer(const byte* buff, const uint8_t size, const boolean asChars, const char* header) {
  char b[strlen(header) + 2 + size * 3 + 1] { 0 };
  Serial.println(printBuffer(buff, size, asChars, header, b));
  delay(5);
}

char* printBuffer(const byte* buff, const uint8_t size, const boolean asChars, const char* header, char* output) {
  if (size == 0) {
    output[0] = 0x00;
    return output;
  }

  char temp[strlen(header) + 2 + size * 3 + 1] { 0 };
  if (strlen(header) > 0) {
    strcat(temp, header);
    strcat(temp, ": ");
  }
  for (int i = 0; i < size; i++) {
    if (asChars) {
      strncat(temp, (const char*)&buff[i], 1);
    } else {
      char hex[4];
      sprintf(hex, "%02X ", buff[i]);
      strcat(temp, hex);
    }
  }
  strcpy(output, temp);
  return output;
}

} // namespace EnOcean
