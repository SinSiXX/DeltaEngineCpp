#ifndef		HYPODERMIC_COMPONENT_REGISTRY_H_
# define	HYPODERMIC_COMPONENT_REGISTRY_H_

# include <memory>
# include <unordered_map>
# include <vector>

# include <boost/thread.hpp>

# include <Hypodermic/IComponentRegistry.h>
# include <Hypodermic/ServiceKey.h>
# include <Hypodermic/ServiceRegistrationInfo.h>


namespace Hypodermic
{
    class IComponentRegistration;


	class ComponentRegistry : public IComponentRegistry
	{
		typedef std::unordered_map< ServiceKey, std::shared_ptr< ServiceRegistrationInfo > > ServiceRegistrationInfos;

	public:
		std::shared_ptr< IComponentRegistration > getRegistration(std::shared_ptr< Service > service);

		bool isRegistered(std::shared_ptr< Service > service);

		void addRegistration(std::shared_ptr< IComponentRegistration > registration);

        void addRegistration(std::shared_ptr< IComponentRegistration > registration, bool preserveDefaults);

		std::vector< std::shared_ptr< IComponentRegistration > > registrations();

		std::vector< std::shared_ptr< IComponentRegistration > > registrationsFor(std::shared_ptr< Service > service);

	private:
		std::shared_ptr< ServiceRegistrationInfo > getServiceInfo(std::shared_ptr< Service > service);

        
        std::vector< std::shared_ptr< IComponentRegistration > > registrations_;
		ServiceRegistrationInfos serviceInfo_;
		boost::recursive_mutex mutex_;
	};

} // namespace Hypodermic


#endif /* !HYPODERMIC_COMPONENT_REGISTRY_H_ */