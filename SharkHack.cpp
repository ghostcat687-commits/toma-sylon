#include "core/SharkHack.hpp"

#include "core/SettingsManager.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace shark {

SharkHack& SharkHack::get() {
    static SharkHack instance;
    return instance;
}

void SharkHack::onModLoaded() {
    SettingsManager::get().migrate();
    m_loaded = true;
    log::info("Shark Hack {} loaded (Geode {}, built for GD {})", modVersion(), loaderVersion(), kTargetGameVersion);
}

std::string SharkHack::modVersion() const {
    return Mod::get()->getVersion().toVString();
}

std::string SharkHack::loaderVersion() const {
    return Loader::get()->getVersion().toVString();
}

} // namespace shark
