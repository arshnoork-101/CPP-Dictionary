# 📖 CPP-Dictionary App 

This project implements a dictionary application that loads words and their definitions from a CSV file, allowing users to search for word definitions.

## Project Overview

The application reads word definitions from a CSV file, stores them in memory, and provides search functionality. It also measures and logs the duration of various operations ⏱️.

## Features

- 📥 **Dictionary Loading:** Loads words, parts of speech, and definitions from a CSV file.
- 🔎 **Word Search:** Searches for word definitions with optional part-of-speech display.
- ⚙️ **Settings:** Configurable output options (show all definitions, verbose mode, time units).
- 🧾 **Event Logging:** Measures and logs the duration of operations.
- ⏲️ **Time Monitoring:** Uses `std::chrono` for precise time measurement.
- ❗ **Error Handling:** Handles file open errors and invalid parts of speech.

## Project Structure

```
├── src/
│   ├── dictionary.cpp
│   ├── dictionary.h
│   ├── event.cpp
│   ├── event.h
│   ├── logger.cpp
│   ├── logger.h
│   ├── settings.cpp
│   ├── settings.h
│   ├── timeMonitor.cpp
│   ├── timeMonitor.h
│   └── tester_1.cpp     
├── data/
|   ├── english_large.csv
|   ├── english_small.csv
├── testers/
|   ├── tester_1.cpp
├── README.md

```


## 🧩 Modules

- ⚙️ **settings:** Manages application configuration.
- 🗓️ **event:** Stores information about a single event.
- 📋 **logger:** Manages a collection of events.
- ⌛ **timeMonitor:** Measures the duration of operations.
- 📚 **dictionary:** Manages the dictionary data and search functionality.

## ✅ Conclusion

This project implements a dictionary application 📖 with robust features for loading, searching, and logging data. It demonstrates efficient data management and time measurement using C++ standards, providing a foundation for more advanced text processing applications. 🔍

