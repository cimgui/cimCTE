local defs = {}
defs["Identifiers"] = "std::unordered_map<std::string,Identifier>"
defs["Line"] = "std::vector<Glyph>"
defs["Palette"] = "std::array<ImU32,(unsigned)PaletteIndex::Max>"
defs["TextEditor"] = "struct TextEditor"
defs["TokenRegexString"] = "std::pair<std::string,PaletteIndex>"
defs["TokenizeCallback"] = "bool(*)(const char* in_begin,const char* in_end,const char*& out_begin,const char*& out_end,PaletteIndex& paletteIndex);"

return defs