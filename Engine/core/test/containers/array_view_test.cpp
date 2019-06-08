#include <catch2/catch.hpp>

#include <array>
#include <vector>

#include "beyond/core/containers/array_view.hpp"

TEST_CASE("ArrayView constructors", "[beyond.core.containers.array_view]")
{
  SECTION("Default constructor")
  {
    beyond::ArrayView<int> view;
    REQUIRE(view.empty());
    REQUIRE(view.size() == 0);
  }

  SECTION("Create from a pointer and size")
  {
    constexpr std::size_t size = 3;
    const int data[size] = {0, 1, 2};

    beyond::ArrayView<int> view{static_cast<const int*>(data), size};
    REQUIRE(!view.empty());
    REQUIRE(view.size() == size);
    CHECK(view.data()[0] == 0);
    CHECK(view.data()[1] == 1);
    CHECK(view.data()[2] == 2);
  }

  SECTION("Create from a pointer and size")
  {
    constexpr std::size_t size = 3;
    constexpr int data[size] = {0, 1, 2};

    beyond::ArrayView<int> view{static_cast<const int*>(data), size};
    REQUIRE(view.size() == size);
    CHECK(view.data()[0] == 0);
    CHECK(view.data()[1] == 1);
    CHECK(view.data()[2] == 2);
  }

  SECTION("Create from a raw array")
  {
    constexpr std::size_t size = 3;
    constexpr int data[size] = {0, 1, 2};

    beyond::ArrayView<int> view{data};
    REQUIRE(view.size() == size);
    CHECK(view.data()[0] == 0);
    CHECK(view.data()[1] == 1);
    CHECK(view.data()[2] == 2);
  }

  SECTION("Create from a std::array")
  {
    std::array<int, 3> v{0, 1, 2};

    beyond::ArrayView<int> view{v};
    REQUIRE(view.size() == v.size());
    CHECK(view.data()[0] == v[0]);
    CHECK(view.data()[1] == v[1]);
    CHECK(view.data()[2] == v[2]);
  }

  SECTION("Create from a std::vector")
  {
    std::vector<int> v{0, 1, 2};

    beyond::ArrayView<int> view{v};
    REQUIRE(view.size() == v.size());
    CHECK(view.data()[0] == v[0]);
    CHECK(view.data()[1] == v[1]);
    CHECK(view.data()[2] == v[2]);
  }
}

TEST_CASE("ArrayView accessors", "[beyond.core.containers.array_view]")
{

  std::array a{0, 1, 2};
  beyond::ArrayView<int> view{a};

  SECTION("index accessor")
  {
    REQUIRE(view[0] == 0);
    REQUIRE(view(1) == 1);
  }

  SECTION("front and back")
  {
    REQUIRE(view.front() == 0);
    REQUIRE(view.back() == 2);
  }
}

TEST_CASE("ArrayView iterator", "[beyond.core.containers.array_view]")
{

  std::array a{0, 1, 2};
  beyond::ArrayView<int> view{a};

  CHECK(*view.begin() == 0);
  CHECK(*(view.end() - 1) == 2);
  CHECK(view.end() - view.begin() == 3);
}
