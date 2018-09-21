/// \copyright The Unlicense

#include "rrcxx/prototypes/igcf2/order.hxx"

namespace rrcxx::prototypes::igcf2 {

uuid order::insert_remote_item()
{
    const uuid uuid {generate_uuid()};

    auto derived_ptr {std::make_unique<remote_item>()};
    derived_ptr->id = uuid;

    auto base_ptr {std::unique_ptr<item_base>(derived_ptr.release())};
    auto pair {std::make_pair(uuid, std::move(base_ptr))};
    {
        std::lock_guard<std::mutex> lock_guard(items_mutex);
        items.insert(std::move(pair));
    }

    return uuid;
}

remote_item &order::find_remote_item(const uuid &uuid)
{
    const auto it {items.find(uuid)};
    if (it == items.end())
        throw std::exception("The target item not found.");

    const auto &base_ptr {it->second.get()};
    if (base_ptr->type() != item_base::type::remote)
        throw std::exception("The target item isn't remote_item.");

    const auto derived_ptr {dynamic_cast<remote_item *>(base_ptr)};
    return *derived_ptr;
}

}//namespace rrcxx::prototypes::igcf2
