from Client import Client


def rtsp_payload(client: Client, sequence_number: int, request: int, video_file: str, rtp_port: int) -> None:
    """
    Construct the RTSP payload for the client to send to the server.
    :param client: The client this packet is from.
    :param sequence_number: The sequence number of the packet.
    :param request: The request type being either 0 for SETUP, 1 for PLAY, 2 for PAUSE, or 3 for TEARDOWN.
    :param video_file: The name of the video file.
    :param rtp_port: The RTP port to stream over.
    :return: Nothing.
    """
    if request == 0:
        client.data = "{seqNum}|{req}|{vid}|{rtp}".format(seqNum = sequence_number, req = request, vid = video_file, rtp = rtp_port)
    else:
        client.data = "{seqNum}|{req}".format(seqNum = sequence_number, req = request)  # TODO


def rtp_header(header: bytearray, version: int, padding: int, extension: int, cc: int, marker: int, payload_type: int, sequence_number: int, timestamp: int, ssrc: int) -> None:
    """
    Encode the RTP header fields for the server to send to the client.
    :param header: The header byte array of 12 bytes to fill.
    :param version: (2 bits) Indicates the version of the protocol.
    :param padding: (1 bit) Used to indicate if there are extra padding bytes at the end of the RTP packet.
    Padding may be used to fill up a block of certain size, for example as required by an encryption algorithm.
    The last byte of the padding contains the number of padding bytes that were added (including itself).
    :param extension: (1 bit) Indicates presence of an extension header between the header and payload data.
    The extension header is application or profile specific.
    :param cc: (4 bits) Contains the number of CSRC identifiers that follow the SSRC.
    :param marker: (1 bit) Signaling used at the application level in a profile-specific manner.
    If it is set, it means that the current data has some special relevance for the application.
    :param payload_type: (7 bits) Indicates the format of the payload and thus determines its interpretation by the
    application. Values are profile specific and may be dynamically assigned.
    :param sequence_number: (16 bits) The sequence number is incremented for each RTP data packet sent and is to be used
    by the receiver to detect packet loss and to accommodate out-of-order delivery.
    :param timestamp: The timestamp for use in certain header fields.
    :param ssrc: (32 bits) Synchronization source identifier uniquely identifies the source of a stream.
    The synchronization sources within the same RTP session will be unique.
    :return: Nothing.
    """
    header[0] = header[0] | version << 6 | padding << 5 | extension << 4 | cc << 0 # TODO
    header[1] = header[1] | marker << 7 | payload_type << 0  # TODO
    header[2] = (sequence_number >> 8) & 0xFF  # TODO
    header[3] = sequence_number & 0xFF  # TODO
    header[4] = (timestamp >> 24) & 0xFF  # TODO
    header[5] = (timestamp >> 16) & 0xFF  # TODO
    header[6] = (timestamp >> 8) & 0xFF  # TODO
    header[7] = timestamp & 0xFF  # TODO
    header[8] = (ssrc >> 24) & 0xFF  # TODO
    header[9] = (ssrc >> 16) & 0xFF  # TODO
    header[10] = (ssrc >> 8) & 0xFF  # TODO
    header[11] = ssrc & 0xFF  # TODO
