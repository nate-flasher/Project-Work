import java.util.*;
import java.io.FileInputStream;
import java.io.*;
import java.lang.*;
import java.nio.*;
public class NTFSDump {


    //the size of each mft entry in NTFS
    private int mftEntrySize = 1024;

    public static void parseMFT(int numberOfMFTEntries, int volumeOffset, File diskImage) throws IOException {
        int bytesPerSector = 512;
        int sectorsPerCluster = 8;
        int numberOfClusters = 4;

        //Total bytes of the disk image
        long lengthOfImage = diskImage.length();
        System.out.println("Total bytes of image: " + lengthOfImage + "\n");

        //the byte offset to get to the mft
        int byteOffset = volumeOffset + (bytesPerSector*sectorsPerCluster*numberOfClusters);
        System.out.println("Byte offset: " + byteOffset + "\n");

        byte [][] allMFTEntries = new byte[numberOfMFTEntries][1024];

        //creates file input stream for the disk image
        InputStream inputStream = new FileInputStream(diskImage);

        //skips (byteOffsett)bytes through the disk image to the MFT
        inputStream.skip(byteOffset);

        //loops through each MFT entry
        for (int i = 0; i < allMFTEntries.length; i++){

            //reads each mft entry one by one
            inputStream.read(allMFTEntries[i], 0, 1024);

            //wraps each MFT entry into a byte buffer
            ByteBuffer forFirstAttributeBuffer = ByteBuffer.wrap(allMFTEntries[i]);

            //sets the byte order of the byte buffer to little endian
            forFirstAttributeBuffer.order(ByteOrder.LITTLE_ENDIAN);

            //gets the offset to each MFT entry's first attribute and stores in in a variable
            int offsetToAttributeHeader = forFirstAttributeBuffer.getShort(20);
            //System.out.println(offsetToFirstAttr + "\n");

           //creates a new byte array for the attribute header of size 16 bytes
            byte [] attributeHeader = new byte [16];

            //loops the attribute header and sets each attribute header's index to the correct offset in it's current MFT entry
            for(int a = 0; a < attributeHeader.length; a++){
                attributeHeader[a] = allMFTEntries[i][offsetToAttributeHeader + a];
            }

            //wraps the attribute header in a byte buffer
            ByteBuffer attributeHeaderBuffer = ByteBuffer.wrap(attributeHeader);

            //sets the byte buffer for the attribute header to use little endian format for bytes
            attributeHeaderBuffer.order(ByteOrder.LITTLE_ENDIAN);

            //grabs the attribute type
            //if value of attributeType = 16: STANDARD_INFO attribute
            //if value of attributeType = 48: FILE_NAME attribute
            //if value of attributeType = 128: DATA attribute
            int attributeType = attributeHeaderBuffer.getInt(0);
            System.out.println(attributeType);

            //gets value of whether or not the attributes are resident or not
            int residentFlag = attributeHeaderBuffer.get(8);

            //if resident flag value is 0 then it is resident
            if(residentFlag == 0){

                //offset to the length of the attribute content = offset to attribute header + 16 bytes
                int offsetToLengthOfAttribute = offsetToAttributeHeader + 16;

                //creating a byte array to store bytes 16-21 (length of attribute and offset to attribute)
                byte [] residentBytes = new byte[6];

                //loops residentBytes array and sets each of its entry to the correct offset in it's current MFT array
                for(int b = 0; b < residentBytes.length; b++){
                    residentBytes[b] = allMFTEntries[i][offsetToLengthOfAttribute + b];
                }
                //wraps the resident bytes in a byte buffer
                ByteBuffer residentBytesBuffer = ByteBuffer.wrap(residentBytes);

                //sets the byte buffer for the resident bytes to use little endian format for bytes
                residentBytesBuffer.order(ByteOrder.LITTLE_ENDIAN);

                //gets the length of the attribute
                int lengthOfAttribute = residentBytesBuffer.getInt(0);
                //System.out.println(lengthOfAttribute);

                //gets the offset to the actual attribute
                int offsetToAttributeFromHeader = residentBytesBuffer.getShort(4);
                //System.out.println(offsetToAttributeFromHeader);

                //gets the final and official offset to the attributes from beginning of MFT entry
                int officialAndFinalOffsetToTheAttributesFromMFTEntryBeginning = offsetToAttributeHeader + offsetToAttributeFromHeader;

                //creates a byte array to store the attribute bytes - the size of all the attributes
                byte [] attributeBytes = new byte[lengthOfAttribute];

                //loops attributeBytes array and sets each of its entry to the correct offset in it's current MFT array
                for(int c = 0; c < attributeBytes.length; c++){
                    attributeBytes[c] = allMFTEntries[i][officialAndFinalOffsetToTheAttributesFromMFTEntryBeginning + c];
                }

                //wraps the attribute bytes in a byte buffer
                ByteBuffer attributeBytesBuffer = ByteBuffer.wrap(attributeBytes);

                //sets the byte buffer for the attribute bytes to use little endian format for bytes
                attributeBytesBuffer.order(ByteOrder.LITTLE_ENDIAN);

                if(attributeType == 16){ //STANDARD_INFO attribute

                    //System.out.println("File type: $STANDARD_INFORMATION (0x10)");

                    int fileCreationDate = attributeBytesBuffer.getInt(0);
                    //System.out.println("File creation date: " + fileCreationDate+ "\n");

                    int fileLastModifiedDate = attributeBytesBuffer.getInt(8);
                    //System.out.println(fileLastModifiedDate);

                }

                else if(attributeType == 48){ //FILE_NAME attribute

                    System.out.println("File type: $FILE_NAME (0x30)");

                    int allocatedSizeOfFile = attributeBytesBuffer.getInt(40);
                    //System.out.println(allocatedSizeOfFile + "\n");
                }


            }



        }

        //closes file stream
        inputStream.close();

    }



    public static void main(String[] args) throws IOException {

        // checks to see if the program runs command line file
        if(args.length < 1) {
            System.out.println("Did not run through command line");
            System.exit(1);
        }

        //sets the offset to the mft itself
        int volumeOffset = (Integer.parseInt((args[1])));

        parseMFT(65, volumeOffset, new File(args[0]));


    }


}