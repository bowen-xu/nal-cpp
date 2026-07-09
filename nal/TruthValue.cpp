#include "TruthValue.hpp"

#include <fmt/core.h>

namespace seqnars::nal
{

auto TruthValue::repr() const -> std::string
{
    return fmt::format("<Truth: %{:.2f}, {:.2f}% (k={})>", this->f, this->c, this->k);
}

} // namespace seqnars::nal
