#pragma once

#include <vector>

#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager

struct ParamEntry {
  const char *id;
  const char *label;
  int max_len;
};

class WifiManagerParamHelper {
public:
  WifiManagerParamHelper(WiFiManager &wm) : wm_(wm) {}

  void Init(uint16_t preamble, const ParamEntry *entries, size_t entries_len);

  const char* GetSettingValue(size_t idx) const;

  const WiFiManagerParameter& GetSettingParam(size_t idx) const;

  size_t GetNumSettings() const;

private:
  static constexpr size_t HEADER_SIZE = sizeof(uint16_t) * 2;
  size_t _data_size = 0;
  WiFiManager &wm_;
  std::vector<WiFiManagerParameter> parameters_;

  void OnParamCallback();
};
