#include "Data.h"
#include "Report.h"
Data::Data(const string& path)
{
	try {
		for (directory_iterator i = directory_iterator(path); i != directory_iterator(); i++)
		{
			if (!is_directory(i->path()))
			{
				InfoAboutFiles.push_back(i->path().filename().string());
				InfoAboutFiles.push_back(to_string(i->file_size()));
				InfoAboutFiles.push_back(ConvertTime(i->path()));
			}
			else
				continue;
		}
	}
	catch (const filesystem_error& FsError) {
		cout << FsError.what() << endl;
		cout << FsError.code() << endl;
	}
}

const vector<string> Data::ReadInfoAboutFiles()
{
	const vector<string> ReadInfoAboutFile = move(InfoAboutFiles);
	return ReadInfoAboutFile;
}

char* Data::ConvertTime(const path& path) const
{
	auto ftime = last_write_time(path);
	static int64_t sfclock_diff = [] {
		long long diff = int64_t(system_clock::now().time_since_epoch() / milliseconds(1)) -
			int64_t(decltype(ftime)::clock::now().time_since_epoch() / milliseconds(1));
		return (diff + (diff < 0 ? -500 : 500)) / 1000; // Round to nearest second.
	}();

	std::time_t cftime = system_clock::to_time_t(
		time_point<system_clock>(
			seconds(ftime.time_since_epoch() / seconds(1) + sfclock_diff)
			)
	);
	char* normalTime = asctime(localtime(&cftime));
	return normalTime;
}