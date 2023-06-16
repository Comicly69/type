#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    const char *extension;
    const char *type;
} FileType;

// Define the file type mappings
const FileType fileTypes[] = {
    {".txt", "Text file"},
    {".mov", "Movie file"},
    {".jpg", "JPEG image file"},
    {".jpeg", "JPEG image file"},
    {".png", "PNG image file"},
    {".pdf", "PDF document"},
    {".doc", "Microsoft Word document"},
    {".docx", "Microsoft Word document"},
    {".xls", "Microsoft Excel spreadsheet"},
    {".xlsx", "Microsoft Excel spreadsheet"},
    {".ppt", "Microsoft PowerPoint presentation"},
    {".pptx", "Microsoft PowerPoint presentation"},
    {".zip", "ZIP archive"},
    {".rar", "RAR archive"},
    {".tar", "Tarball archive"},
    {".gz", "Gzip archive"},
    {".7z", "7-Zip archive"},
    {".mp3", "MP3 audio file"},
    {".wav", "WAV audio file"},
    {".avi", "AVI video file"},
    {".mp4", "MP4 video file"},
    {".mkv", "Matroska video file"},
    {".wmv", "Windows Media Video file"},
    {".exe", "Executable file"},
    {".dll", "Dynamic Link Library file"},
    {".app", "Application file"},
    {".csv", "Comma-separated values file"},
    {".json", "JSON file"},
    {".xml", "XML file"},
    {".html", "HTML file"},
    {".css", "CSS file"},
    {".js", "JavaScript file"},
    {".py", "Python script file"},
    {".c", "C source code file"},
    {".cpp", "C++ source code file"},
    {".java", "Java source code file"},
    {".php", "PHP script file"},
    {".rb", "Ruby script file"},
    {".pl", "Perl script file"},
    {".sql", "SQL script file"},
    {".log", "Log file"},
    {".bak", "Backup file"},
    {".cfg", "Configuration file"},
    {".ini", "Initialization file"},
    {".dat", "Data file"},
    {".bin", "Binary data file"},
    {".iso", "Disc image file"},
    {".md", "Markdown file"},
    {".gif", "GIF image file"},
    {".bmp", "BMP image file"},
    {".svg", "Scalable Vector Graphics file"},
    {".tif", "TIFF image file"},
    {".mpg", "MPEG video file"},
    {".flv", "Flash video file"},
    {".wma", "Windows Media Audio file"},
    {".aac", "Advanced Audio Coding file"},
    {".ppt", "PowerPoint presentation"},
    {".xls", "Excel spreadsheet"},
    {".doc", "Word document"},
    {".odt", "OpenDocument Text document"},
    {".ods", "OpenDocument Spreadsheet"},
    {".odp", "OpenDocument Presentation"},
    {".odg", "OpenDocument Graphics"},
    {".odf", "OpenDocument Formula"},
    {".csv", "Comma-separated values file"},
    {".tsv", "Tab-separated values file"},
    {".txt", "Plain text file"},
    {".rtf", "Rich Text Format file"},
    {".htm", "HTML file"},
    {".html", "HTML file"},
    {".xhtml", "XHTML file"},
    {".css", "CSS file"},
    {".js", "JavaScript file"},
    {".php", "PHP script file"},
    {".asp", "Active Server Pages script file"},
    {".aspx", "Active Server Pages script file"},
    {".jsp", "JavaServer Pages script file"},
    {".py", "Python script file"},
    {".sh", "Shell script file"},
    {".bat", "Batch file"},
    {".cmd", "Windows Command Script file"},
    {".vbs", "VBScript file"},
    {".jar", "Java Archive file"},
    {".war", "Web Application Archive file"},
    {".ear", "Enterprise Archive file"},
    {".class", "Java class file"},
    {".obj", "Object file"},
    {".o", "Object file"},
    {".lib", "Library file"},
    {".so", "Shared object file"},
    {".dll", "Dynamic Link Library file"},
    {".pdb", "Program database file"},
    {".mdb", "Microsoft Access database file"},
    {".accdb", "Microsoft Access database file"},
    {".sql", "SQL database file"},
    {".db", "Database file"},
    {".dbf", "Database file"},
    {".xls", "Microsoft Excel spreadsheet"},
    {".xlsx", "Microsoft Excel spreadsheet"},
    {".csv", "Comma-separated values file"},
    {".mdb", "Microsoft Access database file"},
    {".accdb", "Microsoft Access database file"},
    {".pst", "Outlook Personal Information Store file"},
    {".eml", "Email message file"},
    {".msg", "Outlook Mail Message file"},
    {".ost", "Outlook Offline Data File"},
    {".ics", "Calendar file"},
    {".vcf", "vCard file"},
    {".txt", "Text file"},
    {".log", "Log file"},
    {".cfg", "Configuration file"},
    {".ini", "Initialization file"},
    {".bak", "Backup file"},
    {".tmp", "Temporary file"},
    {".temp", "Temporary file"},
    {".swp", "Swap file"},
    {".part", "Partially downloaded file"},
    {".crdownload", "Chrome partially downloaded file"},
    {".db", "Database file"},
    {".torrent", "BitTorrent file"},
    {".ics", "iCalendar file"},
    {".psd", "Adobe Photoshop document"},
    {".ai", "Adobe Illustrator document"},
    {".indd", "Adobe InDesign document"},
    {".eps", "Encapsulated PostScript file"},
    {".cdr", "CorelDRAW document"},
    {".svg", "Scalable Vector Graphics file"},
    {".odp", "OpenDocument Presentation"},
    {".ods", "OpenDocument Spreadsheet"},
    {".odt", "OpenDocument Text document"},
    {".pages", "Pages document"},
    {".numbers", "Numbers spreadsheet"},
    {".key", "Keynote presentation"},
    {".mdb", "Microsoft Access database file"},
    {".accdb", "Microsoft Access database file"},
    {".pst", "Outlook Personal Information Store file"},
    {".eml", "Email message file"},
    {".msg", "Outlook Mail Message file"},
    {".oft", "Outlook Item Template file"},
    {".oft", "Outlook File Template file"},
    {".idx", "Outlook Express Mailbox Index file"},
    {".mbx", "Outlook Express Mailbox file"},
    {".wab", "Windows Address Book file"},
    {".jpeg", "JPEG image file"},
    {".jpg", "JPEG image file"},
    {".gif", "GIF image file"},
    {".bmp", "BMP image file"},
    {".png", "PNG image file"},
    {".tif", "TIFF image file"},
    {".tiff", "TIFF image file"},
    {".ico", "Icon file"},
    {".raw", "Raw image file"},
    {".svg", "Scalable Vector Graphics file"},
    {".pdf", "PDF document"},
    {".eps", "Encapsulated PostScript file"},
    {".ps", "PostScript file"},
    {".txt", "Plain text file"},
    {".rtf", "Rich Text Format file"},
    {".doc", "Microsoft Word document"},
    {".docx", "Microsoft Word document"},
    {".xls", "Microsoft Excel spreadsheet"},
    {".xlsx", "Microsoft Excel spreadsheet"},
    {".ppt", "Microsoft PowerPoint presentation"},
    {".pptx", "Microsoft PowerPoint presentation"},
    {".pub", "Microsoft Publisher document"},
    {".vsd", "Microsoft Visio document"},
    {".mpp", "Microsoft Project document"},
    {".accdb", "Microsoft Access database file"},
    {".mdb", "Microsoft Access database file"},
    {".pst", "Outlook Personal Information Store file"},
    {".eml", "Email message file"},
    {".msg", "Outlook Mail Message file"},
    {".ost", "Outlook Offline Data File"},
    {".ics", "Calendar file"},
    {".vcf", "vCard file"},
    {".apk", "Android Package file"},
    {".ipa", "iOS Application file"},
    {".exe", "Executable file"},
    {".msi", "Windows Installer package"},
    {".dmg", "Mac OS X Disk Image"},
    {".pkg", "Installer package"},
    {".deb", "Debian package"},
    {".rpm", "Red Hat Package Manager file"},
    {".tar", "Tarball archive"},
    {".gz", "Gzip archive"},
    {".bz2", "Bzip2 archive"},
    {".7z", "7-Zip archive"},
    {".zip", "ZIP archive"},
    {".rar", "RAR archive"},
    {".tar.gz", "Tarball archive"},
    {".tar.bz2", "Bzip2 compressed tar archive"},
    {".iso", "Disc image file"},
    {".img", "Disk image file"},
    {".toast", "Toast disc image file"},
    {".vcd", "Virtual CD file"},
    {".sql", "SQL script file"},
    {".db", "Database file"},
    {".mdb", "Microsoft Access database file"},
    {".accdb", "Microsoft Access database file"},
    {".xls", "Microsoft Excel spreadsheet"},
    {".xlsx", "Microsoft Excel spreadsheet"},
    {".csv", "Comma-separated values file"},
    {".xml", "XML file"},
    {".html", "HTML file"},
    {".htm", "HTML file"},
    {".css", "CSS file"},
};

const size_t numFileTypes = sizeof(fileTypes) / sizeof(FileType);

typedef struct {
    const char *extension;
    const char *type;
} FileTypeHashEntry;

#define HASH_TABLE_SIZE 1009

FileTypeHashEntry *fileTypeHashTable[HASH_TABLE_SIZE] = { NULL };

// Hash function
unsigned int hash(const char *extension) {
    unsigned int hashValue = 0;

    while (*extension) {
        hashValue = (hashValue << 5) + *extension++;
    }

    return hashValue % HASH_TABLE_SIZE;
}

// Insert a file type entry into the hash table
void insertFileTypeHashEntry(const char *extension, const char *type) {
    unsigned int index = hash(extension);

    while (fileTypeHashTable[index] != NULL) {
        index = (index + 1) % HASH_TABLE_SIZE;
    }

    FileTypeHashEntry *entry = (FileTypeHashEntry *)malloc(sizeof(FileTypeHashEntry));
    entry->extension = extension;
    entry->type = type;
    fileTypeHashTable[index] = entry;
}

// Retrieve the file type from the hash table
const char *getFileTypeFromHash(const char *extension) {
    unsigned int index = hash(extension);
    unsigned int startIndex = index;  // Store the starting index for error handling

    while (fileTypeHashTable[index] != NULL) {
        if (strcmp(extension, fileTypeHashTable[index]->extension) == 0) {
            return fileTypeHashTable[index]->type;
        }

        index = (index + 1) % HASH_TABLE_SIZE;

        // If we have looped back to the starting index, it means the extension is not found
        if (index == startIndex) {
            break;
        }
    }

    return NULL;
}

// Initialize the hash table
void initializeHashTable() {
    for (size_t i = 0; i < numFileTypes; i++) {
        insertFileTypeHashEntry(fileTypes[i].extension, fileTypes[i].type);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    initializeHashTable();

    char *filename = argv[1];
    char *extension = strrchr(filename, '.');  // Find the last occurrence of '.'

    if (extension == NULL) {
        printf("No file extension found.\n");
        return 1;  // Return an error code to indicate the issue
    } else {
        const char *fileType = getFileTypeFromHash(extension);
        if (fileType != NULL) {
            printf("File type: %s\n", fileType);
        } else {
            printf("Unknown file type for extension: %s\n", extension);
            return 1;  // Return an error code to indicate the issue
        }
    }

    return 0;
}
