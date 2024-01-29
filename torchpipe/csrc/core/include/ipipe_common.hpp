// Copyright 2021-2024 NetEase.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#define IPIPE_EXPORT __attribute__((visibility("default")))
#define IPIPE_LOCAL __attribute__((visibility("hidden")))
namespace {
// constexpr
constexpr const char* file_name(const char* path) {
  const char* file = path;
  while (*path) {
    if (*path++ == '/') {
      file = path;
    }
  }
  return file;
}
}  // namespace

#define IPIPE_CHECK(x, args...)                                                                  \
  do {                                                                                           \
    if (!(x)) {                                                                                  \
      throw std::runtime_error("[" + std::string(file_name(__FILE__)) + ":" +                    \
                               std::to_string(__LINE__) + std::string(" ") +                     \
                               std::string(__FUNCTION__) + std::string("]: assert `") +          \
                               std::string(#x) + std::string("` failed. ") + std::string(args)); \
    }                                                                                            \
  } while (false)

#define IPIPE_ASSERT(x)                                                                 \
  do {                                                                                  \
    if (!(x)) {                                                                         \
      throw std::runtime_error("[" + std::string(file_name(__FILE__)) + ":" +           \
                               std::to_string(__LINE__) + std::string(" ") +            \
                               std::string(__FUNCTION__) + std::string("]: assert `") + \
                               std::string(#x) + std::string("` failed. "));            \
    }                                                                                   \
  } while (false)

#define IPIPE_THROW(args...)                                                                      \
  {                                                                                               \
    throw std::runtime_error("[" + std::string(file_name(__FILE__)) + ":" +                       \
                             std::to_string(__LINE__) + std::string(" ") +                        \
                             std::string(__FUNCTION__) + std::string("]: ") + std::string(args)); \
  }
