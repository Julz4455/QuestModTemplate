#define RAPIDJSON_HAS_STDSTRING 1

#include "main.hpp"
#include "ModConfig.hpp"

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo, LoggerOptions(false, false));
    return *logger;
}

DEFINE_CONFIG(#{base_class_name}Config);

auto cs2utf8(Il2CppString *t) {
    return to_utf8(csstrtostr(t));
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = "#{id}";
    info.version = "0.1.0";
    modInfo = info;
	
    getModConfig().Init(modInfo);
    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Installing hooks...");
    getLogger().info("Installed all hooks!");
}