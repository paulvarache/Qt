// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/renderer/chrome_object_extensions_utils.h"

#include "gin/converter.h"
#include "v8/include/v8.h"

namespace content {

v8::Handle<v8::Object> GetOrCreateChromeObject(
    v8::Isolate* isolate, v8::Handle<v8::Object> global) {
  v8::Handle<v8::Object> chrome;
  v8::Handle<v8::Value> chrome_value =
      global->Get(gin::StringToV8(isolate, "chrome"));
  if (chrome_value.IsEmpty() || !chrome_value->IsObject()) {
    chrome = v8::Object::New(isolate);
    global->Set(gin::StringToSymbol(isolate, "chrome"), chrome);
  } else {
    chrome = chrome_value->ToObject();
  }
  return chrome;
}

} // namespace content
