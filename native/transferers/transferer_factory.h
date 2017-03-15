#ifndef TRANFERER_FACTORY_H
#define TRANFERER_FACTORY_H

#include "url.h"
#include "transferer.h"

BEGIN_C_DECLS

/*
 * transferer_factory��transferer�Ĺ�����
 * transfererʹ����ֻ��ͨ��transferer_factory�����ʹ���transferer��
 * transferer��ʵ��������Ҫ��transferer_factoryע�ᡣ
 */

typedef struct _transferer_desc_t {
	const char* name;                          //transferer�����֡�
	transferer_create_t create;                //transferer�Ĺ��캯��
	transferer_get_props_desc_t get_props_desc;//transferer�����������ļ���
}transferer_desc_t;


/**
 * \brief �����Ѿ�ע���transferer����
 *
 * \param[in] visit       �� ����ʱ�Ļص�������
 * \param[in] ctx         �� ����ʱ�Ļص������������ġ�
 *
 * \retval TRUE  �ɹ�
 * \retval FALSE ʧ�� 
*/
bool_t transferer_factory_foreach(visit_func_t visit, void* ctx);

/**
 * \brief ע���transferer����
 *
 * \param[in] transferer_desc �� ����ʱ�Ļص������������ġ�
 *
 * \retval TRUE  �ɹ�
 * \retval FALSE ʧ�� 
*/
bool_t transferer_factory_register(const transferer_desc_t* transferer_desc);

/**
 * \brief ע����transferer����
 *
 * \param[in] transferer_desc �� ����ʱ�Ļص������������ġ�
 *
 * \retval TRUE  �ɹ�
 * \retval FALSE ʧ�� 
*/
bool_t transferer_factory_unregister(const transferer_desc_t* transferer_desc);

/**
 * \brief ����֧��ָ��URL��transferer����
 *
 * \param[in] url �� url��url��Э��(schema)��transferer��name���бȽϡ�
 *
 * \retval transferer����
*/
transferer_t* transferer_factory_create(url_t* url);

END_C_DECLS

#endif//TRANFERER_FACTORY_H

