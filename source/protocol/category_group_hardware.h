//
// PROJECT:         Aspia Remote Desktop
// FILE:            protocol/category_group_hardware.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_PROTOCOL__CATEGORY_GROUP_HARDWARE_H
#define _ASPIA_PROTOCOL__CATEGORY_GROUP_HARDWARE_H

#include "base/macros.h"
#include "protocol/category.h"

namespace aspia {

class CategoryDmiBios : public CategoryInfo
{
public:
    CategoryDmiBios() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiBios);
};

class CategoryDmiSystem : public CategoryInfo
{
public:
    CategoryDmiSystem() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiSystem);
};

class CategoryDmiBaseboard : public CategoryInfo
{
public:
    CategoryDmiBaseboard() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiBaseboard);
};

class CategoryDmiChassis : public CategoryInfo
{
public:
    CategoryDmiChassis() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiChassis);
};

class CategoryDmiCaches : public CategoryInfo
{
public:
    CategoryDmiCaches() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiCaches);
};

class CategoryDmiProcessors : public CategoryInfo
{
public:
    CategoryDmiProcessors() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiProcessors);
};

class CategoryDmiMemoryDevices : public CategoryInfo
{
public:
    CategoryDmiMemoryDevices() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiMemoryDevices);
};

class CategoryDmiSystemSlots : public CategoryInfo
{
public:
    CategoryDmiSystemSlots() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiSystemSlots);
};

class CategoryDmiPortConnectors : public CategoryInfo
{
public:
    CategoryDmiPortConnectors() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiPortConnectors);
};

class CategoryDmiOnboardDevices : public CategoryInfo
{
public:
    CategoryDmiOnboardDevices() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiOnboardDevices);
};

class CategoryDmiBuildinPointing : public CategoryInfo
{
public:
    CategoryDmiBuildinPointing() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiBuildinPointing);
};

class CategoryDmiPortableBattery : public CategoryInfo
{
public:
    CategoryDmiPortableBattery() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiPortableBattery);
};

class CategoryGroupDMI : public CategoryGroup
{
public:
    CategoryGroupDMI() = default;

    const char* Name() const final;
    IconId Icon() const final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryGroupDMI);
};

class CategoryCPU : public CategoryInfo
{
public:
    CategoryCPU() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryCPU);
};

class CategoryOpticalDrives : public CategoryInfo
{
public:
    CategoryOpticalDrives() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryOpticalDrives);
};

class CategoryATA : public CategoryInfo
{
public:
    CategoryATA() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryATA);
};

class CategorySMART : public CategoryInfo
{
public:
    CategorySMART() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategorySMART);
};

class CategoryGroupStorage : public CategoryGroup
{
public:
    CategoryGroupStorage() = default;

    const char* Name() const final;
    IconId Icon() const final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryGroupStorage);
};

class CategoryVideoAdapters : public CategoryInfo
{
public:
    CategoryVideoAdapters() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryVideoAdapters);
};

class CategoryMonitor : public CategoryInfo
{
public:
    CategoryMonitor() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryMonitor);
};

class CategoryGroupDisplay : public CategoryGroup
{
public:
    CategoryGroupDisplay() = default;

    const char* Name() const final;
    IconId Icon() const final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryGroupDisplay);
};

class CategoryPrinters : public CategoryInfo
{
public:
    CategoryPrinters() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryPrinters);
};

class CategoryPowerOptions : public CategoryInfo
{
public:
    CategoryPowerOptions() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryPowerOptions);
};

class CategoryWindowsDevices : public CategoryInfo
{
public:
    CategoryWindowsDevices() = default;

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Output* output, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryWindowsDevices);
};

class CategoryGroupHardware : public CategoryGroup
{
public:
    CategoryGroupHardware() = default;

    const char* Name() const final;
    IconId Icon() const final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryGroupHardware);
};

} // namespace aspia

#endif // _ASPIA_PROTOCOL__CATEGORY_GROUP_HARDWARE_H
