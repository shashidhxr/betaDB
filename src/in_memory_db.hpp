#ifndef IN_MEMORY_DB_HPP_
#define IN_MEMORY_DB_HPP_

#include <optional>
#include <string>
#include <vector>

/**
 * `InMemoryDB` interface.
 */
struct InMemoryDB {

  /**
   * Should insert a `field`-`value` pair to the record
   * associated with `key`.
   * If the `field` in the record already exists, replace the
   * existing value with the specified `value`.
   * If the record does not exist, create a new one.
   */
  virtual void Set(const std::string& key, const std::string& field, const std::string& value) {
    // Default implementation
  }

  /**
   * Should return the value contained within `field` of the
   * record associated with `key`.
   * If the record or the `field` doesn't exist, should return
   * `std::nullopt`.
   */
  virtual std::optional<std::string> Get(const std::string& key, const std::string& field) {
    // Default implementation
    return std::nullopt;
  }

  /**
   * Should remove the `field` from the record associated with
   * `key`.
   * Returns `true` if the field was successfully deleted, and
   * `false` if the `key` or the `field` do not exist in the
   * database.
   */
  virtual bool Delete(const std::string& key, const std::string& field) {
    // Default implementation
    return false;
  }

  /**
   * Should return a list of strings representing the fields of a
   * record associated with `key`.
   * The returned list should be in the following format
   * `["<field_1>(<value_1>)", "<field_2>(<value_2>)", ...]`,
   * where fields are sorted
   * [lexicographically](keyword://lexicographical-order-for-
   * strings).
   * If the specified record does not exist, returns an empty
   * list.
   */
  virtual std::vector<std::string> Scan(const std::string& key) {
    // Default implementation
    return {};
  }

  /**
   * Should return a list of strings representing some fields of
   * a record associated with `key`.
   * Specifically, only fields that start with `prefix` should be
   * included.
   * The returned list should be in the same format as in the
   * `Scan` operation with fields sorted in
   * [lexicographical](keyword://lexicographical-order-for-
   * strings) order.
   */
  virtual std::vector<std::string> ScanByPrefix(const std::string& key, const std::string& prefix) {
    // Default implementation
    return {};
  }

  /**
   * Should insert a `field`-`value` pair or updates the value of
   * the `field` in the record associated with `key`.
   */
  virtual void SetAt(const std::string& key, const std::string& field, const std::string& value, int timestamp) {
    // Default implementation
  }

  /**
   * Should insert a `field`-`value` pair or update the value of
   * the `field` in the record associated with `key`.
   * Also sets its Time-To-Live starting at `timestamp` to be
   * `ttl`.
   * The `ttl` is the amount of time that this `field`-`value`
   * pair should exist in the database, meaning it will be
   * available during this interval:
   * `[timestamp, timestamp + ttl)`.
   */
  virtual void SetAtWithTtl(const std::string& key, const std::string& field, const std::string& value, int timestamp, int ttl) {
    // Default implementation
  }

  /**
   * The same as `Delete`, but with timestamp of the operation
   * specified.
   * Should return `true` if the field existed and was
   * successfully deleted and `false` if the key didn't exist.
   */
  virtual bool DeleteAt(const std::string& key, const std::string& field, int timestamp) {
    // Default implementation
    return false;
  }

  /**
   * The same as `Get`, but with timestamp of the operation
   * specified.
   */
  virtual std::optional<std::string> GetAt(const std::string& key, const std::string& field, int timestamp) {
    // Default implementation
    return std::nullopt;
  }

  /**
   * The same as `Scan`, but with timestamp of the operation
   * specified.
   */
  virtual std::vector<std::string> ScanAt(const std::string& key, int timestamp) {
    // Default implementation
    return {};
  }

  /**
   * The same as `ScanByPrefix`, but with timestamp of the
   * operation specified.
   */
  virtual std::vector<std::string> ScanByPrefixAt(const std::string& key, const std::string& prefix, int timestamp) {
    // Default implementation
    return {};
  }

  virtual inline ~InMemoryDB() = 0;
};
InMemoryDB::~InMemoryDB() = default;

#endif  // IN_MEMORY_DB_HPP_
