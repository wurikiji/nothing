/*
        Instead of explicitly set singleton instance,
        use IoC container (DI).
*/
#include <boost/di.hpp>

#include "singleton_impl_class.hpp"

using namespace boost;

auto injector = di::make_injector(
    di::bind<Database>.to(SingletonDatabase::get()).in(di::singleton),
    // other configurations
);