#ifndef _WAVAMRCON_H
#define _WAVAMRCON_H

#ifdef __cplusplus
extern "C" {
#endif

#define WAV_HEAD sizeof(struct wave_pcm_hdr)
typedef int SR_DWORD;
typedef short int SR_WORD ;

struct wave_pcm_hdr{ //��Ƶͷ����ʽ
         char            riff[4];                        // = "RIFF"
         SR_DWORD        size_8;                         // = FileSize - 8
         char            wave[4];                        // = "WAVE"
         char            fmt[4];                         // = "fmt "
         SR_DWORD        dwFmtSize;                      // = ��һ���ṹ��Ĵ�С : 16
 
         SR_WORD         format_tag;              // = PCM : 1
         SR_WORD         channels;                       // = ͨ���� : 1
         SR_DWORD        samples_per_sec;        // = ������ : 8000 | 6000 | 11025 | 16000
         SR_DWORD        avg_bytes_per_sec;      // = ÿ���ֽ��� : dwSamplesPerSec * wBitsPerSample / 8
         SR_WORD         block_align;            // = ÿ�������ֽ��� : wBitsPerSample / 8
         SR_WORD         bits_per_sample;         // = ����������: 8 | 16
 
         char            data[4];                        // = "data";
         SR_DWORD        data_size;                // = �����ݳ��� : FileSize - 44 
};
extern struct wave_pcm_hdr pcmwavhdr;

/*******************************************************
��������:��wav��ʽ�ļ������amr��ʽ����  8k ������,������
����:	wavsrc wav��ʽ�������� amrsrc amr��ʽ�������� a_size���ݴ�С
����ֵ: -1 ����ʧ�� 0 ����ɹ�
********************************************************/
extern int WavToAmr8k(const char *wavsrc,char *Outdata,int *OutSize);
/*******************************************************
��������:��wav��ʽ�ļ������amr��ʽ�ļ�
����:	infile �����ļ�·�� outfile ����ļ�·��
����ֵ: -1 ����ʧ�� 0 ����ɹ�
********************************************************/
extern int WavToAmr8kFile(const char *infile,const char *outfile);

/*******************************************************
��������:��Amr��ʽ�ļ������Wav��ʽ�ļ�
����:	infile �����ļ�·�� outfile ����ļ�·��
����ֵ: -1 ����ʧ�� 0 ����ɹ�
********************************************************/
extern int AmrToWav8k(const char *infile,const char *outfile);

#ifdef __cplusplus
}
#endif

#endif