/*
 * based on the example from jupp0r/prometheus-cpp
 */
#include <iostream>
#include <memory>
#include <thread>

#include <prometheus/exposer.h>
#include <prometheus/info.h>
#include <prometheus/registry.h>

namespace prom = prometheus;

int main() {
    prom::Exposer exposer{"127.0.0.1:8080"};
    auto registry = std::make_shared<prom::Registry>();
    auto &version_info = prom::BuildInfo()
                             .Name("versions")
                             .Help("Static info about the library")
                             .Register(*registry);
    version_info.Add({{"prometheus", "1.0"}});
    exposer.RegisterCollectable(registry);

    std::cout << "Hello World!\n";
    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
