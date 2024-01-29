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

#include <vector>

#include "dict.hpp"
namespace ipipe {
std::vector<char> serialize(dict data);
dict deserialize(const std::vector<char>& data);

std::vector<char> serialize(const std::unordered_map<std::string, std::string>& data);
void deserialize(const std::vector<char>& data,
                 std::unordered_map<std::string, std::string>& result);
}  // namespace ipipe
