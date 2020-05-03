/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef RUN_FUNCTION_HPP_
#define RUN_FUNCTION_HPP_

#define RUN_FUNCTION_DIRECTORY "/usr/bin/"

class FRunFunction {
public:
    FRunFunction();
    ~FRunFunction();
    virtual void RunFunctionInit();
    virtual boolean RunFunctionExists();
    virtual void RunFunction(std::string);
};

#endif // RUN_FUNCTION_HPP_