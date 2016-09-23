// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _SSL_METHODS_H_
#define _SSL_METHODS_H_

#define IMPLEMENT_TLS_METHOD_FUNC(func_name, \
                    new, free, \
                    handshake, shutdown, clear, \
                    read, send, pending, \
                    set_fd, get_fd, \
                    set_bufflen, \
                    get_verify_result, \
                    ssl_reload_crt, \
                    get_state) \
        static const SSL_METHOD_FUNC func_name LOCAL_ATRR = { \
                new, \
                free, \
                handshake, \
                shutdown, \
                clear, \
                read, \
                send, \
                pending, \
                set_fd, \
                get_fd, \
                set_bufflen, \
                get_verify_result, \
                ssl_reload_crt, \
                get_state \
        };

#define IMPLEMENT_TLS_METHOD(ver, mode, fun, func_name) \
    const SSL_METHOD* func_name(void) { \
        static const SSL_METHOD func_name##_data LOCAL_ATRR = { \
                ver, \
                mode, \
                &(fun), \
        }; \
        return &func_name##_data; \
    }

#define IMPLEMENT_SSL_METHOD(ver, mode, fun, func_name) \
    const SSL_METHOD* func_name(void) { \
        static const SSL_METHOD func_name##_data LOCAL_ATRR = { \
                ver, \
                mode, \
                &(fun), \
        }; \
        return &func_name##_data; \
    }

#define IMPLEMENT_X509_METHOD(func_name, \
                new, \
                free, \
                load, \
                unload) \
    const X509_METHOD* func_name(void) { \
        static const X509_METHOD func_name##_data LOCAL_ATRR = { \
                new, \
                free, \
                load, \
                unload, \
        }; \
        return &func_name##_data; \
    }

#define IMPLEMENT_PKEY_METHOD(func_name, \
                new, \
                free, \
                load, \
                unload) \
    const PKEY_METHOD* func_name(void) { \
        static const PKEY_METHOD func_name##_data LOCAL_ATRR = { \
                new, \
                free, \
                load, \
                unload, \
        }; \
        return &func_name##_data; \
    }

const X509_METHOD* X509_method(void);
const PKEY_METHOD* EVP_PKEY_method(void);

#endif
